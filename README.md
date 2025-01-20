# <p align="center">PHILOSOPHER [Projet 42]</p>

<div align="center">
	<table>
		<tr><th>NOTE</th>
		<th>ENGLISH VERSION</th></tr>
		<tr><th><img src="https://github.com/mgayout/mgayout/blob/main/img/note/100.png" height="100"></th>
		<th><a href= "https://github.com/mgayout/philosopher/blob/master/eng/README.md"><img src="https://github.com/mgayout/mgayout/blob/main/img/english.png" height="100"></a></th></tr>
	</table>
</div>

## <p> </p>

## <p align="center">INSTALLATION</p>

* Pour télécharger `PHILOSOPHER` :

```shell
git clone https://github.com/mgayout/philosopher.git
```
<div align="center">
	<table>
		<tr><th colspan="2" align="center">Règles</th></tr>
		<tr><td align="center">make</td>
		<td>Compilation</td></tr>
		<tr><td align="center">make clean</td>
		<td>Suppression des fichiers objets</td></tr>
		<tr><td align="center">make fclean</td>
		<td>Suppression des fichiers objets et du programme philo</td></tr>
		<tr><td align="center">make re</td>
		<td>Suppression des fichiers objets et du programme suivi d'une compilation</td></tr>
	</table>
</div>

* Pour tester `PHILOSOPHER` :

```shell
./philo a b c d e
```
* a : Le nombre de philosophe (et de fourchettes)

* b : L'intervalle de temps maximum entre 2 repas

* c : Le temps que prend un philosophe pour manger

* d : Le temps que prend un philosophe pour dormir

* e : Le nombre de repas a atteindre avant d'arrêter la simulation (valeur optionnelle)