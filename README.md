# cube3d

Un moteur de rendu 3D par raycasting, dans l'esprit de Wolfenstein 3D, écrit en C avec la MiniLibX. Projet du tronc commun de 42 Paris, réalisé à deux.

## Ce qui est implémenté

- Parsing d'un fichier de carte `.cub` : textures des quatre murs, couleurs du sol et du plafond, validation de la carte (fermée par des murs, un seul joueur)
- Raycasting colonne par colonne avec textures orientées selon la face du mur
- Déplacements avec `W A S D`, rotation de la caméra avec les flèches
- Gestion propre de la mémoire et des erreurs de parsing

## Architecture

```
src/parsing/    lecture et validation du fichier .cub
src/execution/  raycasting, rendu, entrées clavier
src/free/       libération mémoire
map/            cartes et textures d'exemple
```

## Compiler et lancer

```bash
make
./cube3d map/map.cub
```

Nécessite les dépendances de la MiniLibX (X11 sur Linux).
