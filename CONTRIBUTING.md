# Guide de Contribution - Minishell

---

## 1. Branches principales

### `main`
- C'est la branche avec le code propre et prêt à être livré.
- On ne pousse rien directement dessus.

### `dev`
- C'est là qu'on met tout le travail en cours avant de passer dans `main`.
- Chaque nouvelle feature ou correction part de cette branche et revient dessus après validation.

---

## 2. Workflow de développement

1. **Créer une nouvelle branche à partir de `dev`** :
   ```bash
   git checkout dev
   git pull origin dev  # Mettons à jour pour être sûrs d'avoir tout le dernier taf
   git checkout -b <nom-de-la-branche>
   ```

2. **Comment nommer les branches** :
   - `feature/<nom>` : Pour une nouvelle fonctionnalité. Par exemple :
     - `feature/parsing-quotes` : Pour travailler sur la gestion des quotes dans le parsing.
     - `feature/execution-setup` : Pour mettre en place la structure d'exécution des commandes.
     - `feature/builtin-echo` : Pour implémenter la commande `echo`.
   - `bugfix/<nom>` : Pour corriger un bug. Par exemple :
     - `bugfix/parsing-pipes` : Pour corriger un problème lié à la gestion des pipes dans le parsing.
     - `bugfix/exec-path` : Pour corriger un bug dans la recherche du chemin des commandes.
   - `chore/<nom>` : Pour des tâches techniques ou de maintenance. Par exemple :
     - `chore/documentation` : Pour améliorer ou compléter la documentation.
     - `chore/cleanup-memory` : Pour corriger des problèmes de fuites mémoire.

3. **Faire des commits réguliers et clairs** :
   - Faisons des petits commits pour qu'on puisse suivre ce qui est fait.
   - Utilisons des messages explicites (de préférence en anglais) :
     ```
     feat: Add execution setup structure
     fix: Resolve fd closing issue
     chore: Update documentation for builtins
     ```

4. **Ouvrir une Pull Request (PR)** :
   - Une fois une tâche terminée, ouvrons une PR pour fusionner la branche dans `dev`.
   - Ajoutons une description claire :
     - Ce qui a été fait.
     - Comment tester.
     - Les impacts ou trucs à savoir.

5. **Relecture et validation** :
   - L'autre doit valider la PR avant de fusionner.
   - Modifions si nécessaire jusqu'à ce que ce soit bon.

6. **Fusionner dans `dev` et nettoyer** :
   - Une fois validé, fusionnons dans `dev`.
   - Supprimons la branche pour éviter d'encombrer le dépôt :
     ```bash
     git checkout dev
     git pull origin dev
     git branch -d <nom-de-la-branche>
     git push origin --delete <nom-de-la-branche>
     ```

---

## 3. Tests et validation

- Testons toujours le code avant de faire une PR.
- Vérifions que le code respecte les specs du projet.
- Utilisons `valgrind` pour checker les fuites mémoire.

---

## 4. Règles générales

1. **Respect des consignes du projet** :
   - Suivons les instructions du fichier `minishell.sujet.pdf`.
   - Faisons attention à respecter la norme de codage.

2. **Documentation** :
   - Ajoutons des commentaires dans le code.
   - Mettons à jour le `README.md` si nécessaire.

3. **Communication** :
   - Discutons de ce sur quoi on travaille pour éviter les conflits.
   - En cas de doute, discutons avant de coder.

---