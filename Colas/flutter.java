stless/stfull : digitando isto fora da estrutura do app conseguimos criar novas classes Stateless/StatefulWidget. Stateless não podemos alterar o seu estado (constantes) e Stateful podemos alterar o seu estado (variáveis). São como classes base para a criação de telas.
pubspec.yaml : arquivo de configurações do app

Os atributos das classes do flutter em geral começam com o valor null, por estarem desativados. Por exemplo o valor da mensagem auxiliar de uma caixa de entrada de texto é por padrão nulo, caso seja alguma outra coisa a mensagem aparecerá


Classes úteis
Scaffold - cria o esqueleto da aplicação, possui body, appbar e bottomnavigationbar
GestureDetector - captura gestos do usuário e executa uma função de acordo com o gesto. Child para definir a área onde o gesto será detectado e métodos onTap(), etc para definir as funções de gesto
SingleChildScrollView - necessária caso o conteúdo extrapole a tela, serve para scrollar o conteúdo
Expanded() - suponhamos que estejamos numa row com 3 elementos que não ocupam todo o espaço horizontal. Podemos fazer com que um desses widgets se expandam ocupando o máximo espaço disponível, para isso o colocamos dentro de um expanded

Navigator - necessária para a navegação entre telas. O método .push abre uma tela a ser definida, .pop fecha a tela atual e abre uma nova tela.
Para mudar de tela precisamos informar um context e uma route. Context é definido no método build, 

AssetImage("images/padrao.png") - após os assets serem definidos no pubspec.yaml

TextEditingController _controllerAlcool = TextEditingController(); // Definem controladores para um campo de texto, é útil para alterar ou capturar o valor

https://flutter.dev/docs/development/ui/advanced/gestures


Para mudar a splashscreen ou o ícone devemos mudar nativamente pelo xml de configuração do android, localizado em android/app/src/main/res. Devemos editar o launch_background na pasta drawable para configurar a splashscreen





colocando launcher icons:
dev_dependencies: 
  flutter_test:
    sdk: flutter

  flutter_launcher_icons: "^0.7.2"

flutter_icons:
  image_path: "icon/icon.png" 
  android: true
  ios: true


