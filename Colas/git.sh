passos base:
git add . (adiciona tudo)
git commit -m "mensagem" (commita)
git push (envia)


gerar chave ssh

configura o repositorio em nome de alguem. Caso não coloquemos --global as configurações atuais valem somente para o diretório que estamos trabalhando
git config --global user.name "NOME DO USER"
git config --global user.email "EMAIL DO USER"
git config --global push.default simple - commita apenas trabalhando como uma unica branch
git config --global core.editor gedit - muda o editor das mensagens de commit
git config --global core.pager cat - facilita a visualização de logs no terminal. O padrão é less ao invés de cat
git config --global credential.helper 'cache --timeout=3600' - deixa o nome de usuário e senha salvos, não precisando inseri-los novamente nas requisições. o cache dura uma hora
git config --global merge.tool meld - configura uma boa ferramenta para lidar com conflitos


git help <comando>
git init - o atual diretorio vira um repositorio
git init nome_repo - cria uma nova pasta, sendo ela um novo repo
git add arquivo - adiciona arquivo para o proximo commit
git add . - adiciona tudo o que está na pasta
git commit - faz uma mudança no repo. Ele abre um editor de texto, onde devemos por uma mensagem referente à mudança que fizemos
git commit -m "mensagem de alteração"
git commit -m "." --ammend - as mudanças deste commit são sobrepostas sobre o commit anterior, ou seja, os dois commits se juntam, o mais antigo desaparece e o mais recente permanece, com a alteração dos dois commits juntos
git status - ver status do repo
git log - ver ultimos commits no repo
git log -p - mostra o diff entre as versões
git log --pretty=short - deixa o log conciso
git log --oneline - printa os commits em apenas uma linha, visualização concisa
git log --pretty=format:"%params%" - formata o log com base nos params
git remote add origin "CHAVE SSH" - 
git remote -v  - lista todos os repo remotos
git push -u origin master - seta a branch master e envia os arquivos
git push --set-upstream origin(ou -u) "NOMEDABRANCH" - necessário no primeiro push
git push --set-upstream origin novabranch - para enviar uma nova branch ao remote pela primeira vez
git push <origin> NOMEDABRANCH - também podemos usar ao invés do comando acima
git push - envia os arquivos
git push origin NOMEDABRANCH --delete - deleta a branch remota
git diff - mostra as diferenças do último commit com o que temos no momento4
git diff --staged - caso o git acuse alterações mas git diff não mostrar essas alterações, usar essa flag
git diff HEAD~1 - compara o que está na pasta com 1 commit anterior
git diff CODIGO1 CODIGO2 - compara as diferenças entre dois commits
git diff -w --ignore-blank-lines - diff que não leva em consideração espaços em branco nem linhas em branco

git clone "ULR" - baixa um repo remoto e cria um repo local
git pull - sincroniza baixando os arquivos do servidor remoto
git checkout "CODIGO DO COMMIT" - volta a um estado anterior, no caso, o do commit informado. Arquivos criados posteriormente somem mas não são apagados, alterações posteriores a este commit não são visíveis. Para voltar, fazer git checkout master
git checkout -- arquivo(ou somente .) - desfaz todas as alterações desde o último commit
git checkout HEAD -- arquivo - transforma o arquivo no estado em que ele estava, em determinado HEAD
git revert HEAD - desfaz um commit e volta para o estado anterior a este commit
git reset HEAD - enquanto o revert apenas volta a um commit anterior, o reset volta e APAGA todos os commits posteriores à HEAD informada. O parâmetro --hard volta EXATAMENTE ao commit escolhido, qualquer mudança posterior àquele commit é descartada, por exemplo, o arquivo T foi criado no commit 5, se dermos um reset até o commit 4 usando --hard o arquivo T some.

git branch - retorna a lista de todas as branches e a branch onde você está (*)
git branch "NOME" - cria uma nova branch
git branch -d "NOME" - deleta a branch informada
git checkout "NOMEDABRANCH" - muda para a branch informada
git checkout --orphan NOMEDABRANCH - cria uma branch vazia, sem os elementos já existentes na master

git merge "BRANCH" - aplica os commits da branch informada na branch atual. Se quisermos jogar o conteúdo da master na branch galho, devemos estar em galho (checkout galho) e então damos merge master, e vice versa
git merge --abort - aborta o merge que está sendo executado, caso haja conflito ele é desfeito, o estado dos arquivos retornam para antes de tentar fazer o merge
git mergetool - inicia a ferramenta para lidar com conflitos
git rebase "BRANCH" - parecido com o merge, mas este adiciona primeiro os commits da "BRANCH" e depois os commits da branch onde estamos
git fetch - baixa as atualizações do remote mas não as aplica. Útil para usar um rebase logo em seguida (git pull é a mesma coisa de dar um fetch depois um merge)
git tag "NOMEDATAG" - útil para dermarcar pontos significativos do projeto, uma tag guarda o estado de um repositório e não recebe mais commits. Serve para marcar as versões, por exemplo, versão 1.05 do projeto
git push origin "NOMEDATAG" - envia a tag criada para o remote

git stash - guarda e limpa as alterações da working directory para serem usadas posteriormente
git stash apply - retorna as alterações feitas anteriormente
git stash drop NOMEDOSTASH - remove o stash




Arquivos .md (mark-down)
# string - realça a string, como se fosse o h1 do html
![subtitulo](imagem.jpg) - adiciona uma imagem
