/var/lib/mysql diretorio padrão onde ficam as databases criadas
etc/mysql/mu.cnf  arquivo de configuração
senha root: root
mudar a senha do root: sudo mysqladmin -u root -p password
sudo netstat -tap | grep mysql - status do mysql na máquina



============
ajeitar
CURRENT_DATE - data atual do sistema
HAVING - usamos having ao invés de where para comparar funções de grupo, como count(), max()...
podemos fazer um INSERT INTO tabela (colunas) SELECT (colunas) Where condição - não usamos a clausula values
UPDATE tabela SET coluna=valor, coluna2=valor WHERE condicao
os valores do update podem vir de uma outra tabela
=================

SET SQL_SAFE_UPDATES = 0; - permite usar o UPDATE sem usar uma chave única para buscar a linha


Concatenação: concat()
concate_ws(';', elem1, elem2...) - concatena todos os campos e os separa com o separador informado
group_concat()
IFNULL(atributo, valor) - caso o atributo seja nulo podemos atribuir um valor simbólico para serem feitas operações


show databases; mostra os banco
show tables; mostra as tabelas
describe (ou desc) NomeTabela - descreve a estrutura da tabela, incluindo os tipos de dados de cada atributo

use banco; usa o banco de dados banco

create database nome; cria uma database
create table nome (
    atributo1 tipo,
    atributo2 tipo
);


drop database nome; exclui a database informada
drop table nome; exclui a tabela informada

SELECT * FROM tabela - seleciona tudo da tabela
SELECT atributo AS atrib / SELECT atributo AS 'atrib espaço' / SELECT atributo atrib - renomeia a tabela retornada na consulta
SELECT tabela1.nome, tabela2.nome FROM tabela1, tabela2 - colocando o nome da tabela antes do atributo previne ambiguidade
SELECT DISTINCT continente FROM paises - não retorna resultado repetidos, no caso, não retorna mais do que um continente igual
SELECT nome, continente FROM paises WHERE continent = "South America" - retorna apenas as linhas tal que o continente é igual a South America

SELECT continente FROM paises WHERE continent <> 'Oceania' AND continent <> 'Antarctica' - retorna as linhas tais que o continente não seja oceania ou antartica
SELECT nome, AreaSuperficie from paises WHERE AreaSuperficie BETWEEN 0 AND 1000 - seleciona apenas as linhas que estão naquele intervalo. Também podemos usar NOT BETWEEN para o complemento
SELECT nome FROM paises WHERE continente IN ('Antarctica', 'Oceania') - retorna apenas as linhas onde o continente é antartica ou oceania. O IN serve para listas e para subconsultas de uma única coluna
SELECT codigo FROM paises WHERE codigo LIKE 'C_M' - seleciona todos os atributos tal que _ é qualquer caractere, ex: CAM, COM...
SELECT nome FROM paises WHERE nome LIKE 'Br%' - seleciona todas as linhas tal que o nome começa com Br. Podemos selecionar o complemento do LIKE se usarmos NOT LIKE 'Br%'. Podemos dar escape em caracteres usando \ ou usando a cláusula ESCAPE '%' após o LIKE
SELECT nome, AnoIndependencia FROM paises WHERE AnoIndependencia IS NOT NULL; - retorna todas as linhas em que o campo AnoIndependencia não seja nulo. Não usamos = NULL porque todas as comparações de NULL com = retornam NULL
SELECT nome FROM paises WHERE nome REGEXP '^(.a.a)' - permite usar expressões regulares

SELECT nome, AreaSuperficie FROM paises ORDER BY AreaSuperficie DESC - ordena as linhas retornadas de forma decrescente. ASC para crescente. Podemos fazer ORDER BY atributo1, atributo2, onde a prioriade é ordenar pelo atributo1 e, caso haja colisão, ordena em relação ao atributo2. Cada um desses atributos pode ser ordenado por DESC ou ASC
SELECT * FROM tabela LIMIT 100 - da quantidade retornada pega apenas os 100 primeiros.

SELECT min(valor)/max(valor) - retorna o valor mínimo ou máximo de uma coluna. Útil para subconsultas
SELECT count(nome) FROM paises; - retorna um valor referente a quantidade de nomes presentes na tabela ou seja, a quantidade de linhas não nulas contendo aquele atributo. count(*) conta a quantidade de linhas. As funções avg() e sum() tiram a média e calculam o somatório
SELECT continente, avg(areasuperficie) FROM paises GROUP BY continente - agrupa todos os continentes e tira a média de todos os atributos área. Quando usamos uma função de grupo e também selecionamos um outro atributo somos obrigados a usar a cláusula GROUP BY

SELECT nome, idade FROM pessoa WHERE EXISTS (SELECT idade FROM pessoa WHERE idade > 30) - Checa se existe a subconsulta, então seleciona os atributos.

SELECT nome, areasuperficie,
CASE
    WHEN areasuperficie > 500000 THEN 'O país é grande'
    WHEN areasuperficie = 500000 THEN 'O país é moderado'
    ELSE 'O país é pequeno'
END AS descrição
from paises; - faz uma condicional para cada elemento e retorna o valor apropriado


JOINS

SELECT f.Codigo, f.Nome, e.Descricao
FROM funcionario AS f
INNER JOIN estadocivil AS e ON f.CodigoEstadoCivil = e.Codigo
^^^vvv
SELECT f.Codigo, f.Nome, e.Descricao
FROM funcionario AS f, estadocivil AS e
WHERE f.CodigoEstadoCivil = e.Codigo - o INNER JOIN junta duas tabelas onde o campo de uma é igual ao campo da outra. As duas consultas acima são equivalentes

SELECT f.Codigo, f.Nome, e.Descricao, b.Nome
FROM funcionario AS f
INNER JOIN estadocivil AS e ON funcionario.CodigoEstadoCivil = e.Codigo
INNER JOIN bairro AS b ON f.CodigoBairro = b.Codigo - junção de 3 tabelas. Funciona da seguinte forma: FROM( (tabela INNER JOIN ...) INNER JOIN ..) a tabela faz o primeiro inner join e o resultado retornado, que é outra tabela, vai para o próximo inner join, esta nova tabela depois retornando depois para o from

LEFT JOIN - INNER JOIN que retorna tudo da tabela 1 (esquerda), mesmo se não ocorrer match de valores com a tabela 2 (direita). Se não ocorrer match, retorna NULL no atributo faltante
RIGHT JOIN - análogo
OUTER JOIN - LEFT JOIN + RIGHT JOIN

SELECT cidade FROM clientes
UNION
SELECT cidade FROM fornecedores; - une as duas consultas numa só coluna. UNION ALL retorna também os valores repetidos entre as colunas. Para dar um select os dados selecionados devem ser de natureza similar.


INSERT INTO tabela (atributo1, atributo2) VALUES (v1, v2) - insere os atributos informados dentro da tabela. Caso algum campo não seja informado ele será nulo. Todos os valores devem estar entre aspas simples

UPDATE tabela SET atributo1='v1', atributo2='v2' WHERE (condição) - atualiza todos os campos informados da tabela nas linhas onde a condição WHERE é satisfeita. Caso não haja o WHERE o UPDATE muda todas as linhas.

DELETE FROM tabela; - deleta todos os registro de uma tabela
DELETE FROM  tabela WHERE (condição) - deleta apenas as linhas da tabela tal que a condição WHERE seja satisfeita


CREATE DATABASE nome;
GRANT ALL PRIVILEGES ON nome_do_banco.* TO usuário@localhost; dá acesso ao banco de dados para um usuário
