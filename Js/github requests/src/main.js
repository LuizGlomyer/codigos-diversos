import api from './api';

class App {
    constructor() {
        this.repositories = [];

        this.formEl = document.getElementById('repo-form');
        this.inputEl = document.querySelector('input[name=repository]');
        this.listEl = document.getElementById('repo-list');

        this.registerHandlers();
    }

    registerHandlers(){
        this.formEl.onsubmit = event => this.addRepository(event);
    }

    async addRepository(event) {
        event.preventDefault();
        
        const nameInput = this.inputEl.value;
        if(nameInput.length === 0){
            alert("Insira alguma coisa");
            return;
        }
        
        let response;
        try{
            response = await api.get(`users/${nameInput}`); 
        } catch(err){
            alert('Usuário não existe');
            return;
        }

        console.log(response);

        const name = response.data.login;
        const description = response.data.bio;
        const {html_url, avatar_url} = response.data;
        console.log(name, description, html_url, avatar_url);

        this.repositories.push({
            name,
            description,
            avatar_url,
            html_url
        });

        this.inputEl.value = '';
        this.render();
    }

    render() {
        this.listEl.innerHTML = '';
        this.repositories.forEach(repo => {
            let imgEl = document.createElement('img');
            imgEl.setAttribute('src', repo.avatar_url);

            let titleEl = document.createElement('strong');
            titleEl.appendChild(document.createTextNode(repo.name));

            let descriptionEl = document.createElement('p');
            descriptionEl.appendChild(document.createTextNode(repo.description));

            let linkEl = document.createElement('a');
            linkEl.setAttribute('target', '_blank');
            linkEl.setAttribute('href', repo.html_url)
            linkEl.appendChild(document.createTextNode('Acessar'));

            let listItemEl = document.createElement('li');
            listItemEl.appendChild(imgEl);
            listItemEl.appendChild(titleEl);
            listItemEl.appendChild(descriptionEl);
            listItemEl.appendChild(linkEl);

            this.listEl.appendChild(listItemEl);
        })
    }
}

new App();