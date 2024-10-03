#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nom[50];
    char prenom[50];
    char telephon[11];
    int age;
    char status[20];
    char reference[10];
    char date[11];
} RDV;

RDV rdvs[100] = {
    {"Ahmed", "Benali", "0651234567", 30, "valide", "P0001", "01-10-2024"},
    {"Fatima", "El Amrani", "0652345678", 25, "reporte", "P0002", "02-10-2024"},
    {"Rachid", "Khalil", "0653456789", 45, "annule", "P0003", "03-10-2024"},
    {"Samira", "Safi", "0654567890", 60, "traite", "P0004", "04-10-2024"},
    {"Mouad", "El Ouardi", "0655678901", 22, "valide", "P0005", "05-10-2024"},
    {"Nadia", "Zahir", "0656789012", 33, "reporte", "P0006", "06-10-2024"},
    {"Omar", "Boussoufa", "0657890123", 27, "annule", "P0007", "07-10-2024"},
    {"Imane", "Mouhsine", "0658901234", 37, "traite", "P0008", "08-10-2024"},
    {"Youssef", "Tazi", "0659012345", 41, "valide", "P0009", "09-10-2024"},
    {"Hanan", "Ait Said", "0650123456", 29, "reporte", "P0010", "10-10-2024"}
};

int compteur = 10;

void Afficher_Erreur(const char* message) {
    printf("\033[31m\033[1m%s\033[0m\n", message);
}

void Afficher_Message(const char* message) {
    printf("\033[32m\033[1m%s\033[0m\n", message);
}

void Afficher_Message_tiri(const char* message) {
    printf("\033[33m\033[1m%s\033[0m\n", message);
}

void Menu_Principal() {
    system("cls");
    printf("\n============== Menu Principal ==============\n");
    printf("1- Ajouter un RDV\n");
    printf("2- Modifier ou Supprimer un RDV\n");
    printf("3- Afficher les details d'un RDV\n");
    printf("4- Trier les RDV\n");
    printf("5- Rechercher un RDV\n");
    printf("6- Statistiques\n");
    printf("7- Quitter\n");
}

void Ajouter_RDV() {
    if (compteur >= 100) {
        Afficher_Erreur("Erreur : Limite de RDV atteinte.\n");
        return;
    }

    int stat;
    system("cls");
    printf("====== Saisir les informations du patient ======\n");
    printf("Nom : "); scanf("%s", rdvs[compteur].nom);
    printf("Prenom : "); scanf("%s", rdvs[compteur].prenom);
    printf("Telephone : ");

    scanf("%s", rdvs[compteur].telephon);

    printf("Age : "); scanf("%d", &rdvs[compteur].age);
    printf("Date (jj-mm-aaaa) : "); scanf("%s", rdvs[compteur].date);

    sprintf(rdvs[compteur].reference, "P%02d", compteur + 1);
    printf("Statut (1- valide, 2- reporte, 3- annule, 4- traite): ");
    scanf("%d", &stat);

    switch(stat) {
        case 1: strcpy(rdvs[compteur].status, "valide"); break;
        case 2: strcpy(rdvs[compteur].status, "reporte"); break;
        case 3: strcpy(rdvs[compteur].status, "annule"); break;
        case 4: strcpy(rdvs[compteur].status, "traite"); break;
        default:
            Afficher_Erreur("Votre choix est invalide. RDV non ajoute.\n");
            break;
    }

    compteur++;
    Afficher_Message("(^-^)  &RDV ajoute avec succes.\n");
    system("pause");
}

void Modifier_Ou_Supprimer() {
    int sous_choix;
    char reference[10];


    printf("1- Modifier\t");
    printf("2- Supprimer\t");
    printf("3- Retour\n");
    printf("Taper Votre Choix : ");
    scanf("%d", &sous_choix);

    switch (sous_choix) {
        case 1:
            printf("Entrez la reference du RDV a modifier : ");
            scanf("%s", reference);
            for (int i = 0; i < compteur; i++) {
                if (strcmp(rdvs[i].reference, reference) == 0) {
                    printf("Nouveau nom : "); scanf("%s", rdvs[i].nom);
                    printf("Nouveau prenom : "); scanf("%s", rdvs[i].prenom);
                    printf("Nouveau telephone : "); scanf("%s", rdvs[i].telephon);
                    printf("Nouvel age : "); scanf("%d", &rdvs[i].age);
                    printf("Nouvelle date (jj-mm-aaaa) : "); scanf("%s", rdvs[i].date);
                    Afficher_Message("RDV modifie avec succes.\n");
                    return;
                }
            }
            Afficher_Erreur("() Reference non trouvee.\n");
            break;

        case 2:
            printf("Entrez la reference du RDV a supprimer : ");
            scanf("%s", reference);
            for (int i = 0; i < compteur; i++) {
                if (strcmp(rdvs[i].reference, reference) == 0) {
                    for (int j = i; j < compteur - 1; j++) {
                        rdvs[j] = rdvs[j + 1];
                    }
                    compteur--;
                    Afficher_Message("RDV supprime avec succes.\n");
                    return;
                }
            }
            Afficher_Erreur("Reference non trouvee.\n");
            break;

        case 3:
            return;

        default:
            Afficher_Erreur("Votre choix est invalide.\n");
            break;
    }
}

void Afficher_RDV() {
    char ref[10];
    printf("Taper la reference que vous voulez afficher (ou '.' pour afficher tous les RDV) : ");
    scanf("%s", ref);

    if (strcmp(".", ref) == 0) {
        printf("============================ Details des RDV ============================\n");
        Afficher_Message_tiri("+------------+-----------------+-----------------+-----------------+------+--------------+------------+");
        printf("| %-10s | %-15s | %-15s | %-15s | %-4s | %-12s | %-10s |\n", "Reference", "Nom", "Prenom", "Telephone", "Age", "Date", "Status");
        Afficher_Message_tiri("+------------+-----------------+-----------------+-----------------+------+--------------+------------+");

        for (int i = 0; i < compteur; i++) {
            printf("| %-10s | %-15s | %-15s | %-15s | %-4d | %-12s | %-10s |\n",
                   rdvs[i].reference, rdvs[i].nom, rdvs[i].prenom, rdvs[i].telephon, rdvs[i].age, rdvs[i].date, rdvs[i].status);
        }

        Afficher_Message_tiri("+------------+-----------------+-----------------+-----------------+------+--------------+------------+");
        Modifier_Ou_Supprimer();
        system("pause");
    } else {
        for (int i = 0; i < compteur; i++) {
            if (strcmp(rdvs[i].reference, ref) == 0) {
                printf("============================ Details du RDV ============================\n");
                Afficher_Message_tiri("+----------------------+----------------------+-----------------+------+--------------+------------+");
                printf("| %-20s | %-20s | %-15s | %-4s | %-12s | %-10s |\n", "Nom", "Prenom", "Telephone", "Age", "Date", "Status");
                Afficher_Message_tiri("+----------------------+----------------------+-----------------+------+--------------+------------+");
                printf("| %-20s | %-20s | %-15s | %-4d | %-12s | %-10s |\n",
                   rdvs[i].nom, rdvs[i].prenom, rdvs[i].telephon, rdvs[i].age, rdvs[i].date, rdvs[i].status);
                Afficher_Message_tiri("+----------------------+----------------------+-----------------+------+--------------+------------+\n");
                system("pause");
                return;
            }
        }
        Afficher_Erreur("La reference est introuvable.\n");
    }
}

void Trier_RDV() {
    int choix;
    system("cls");
    printf("====== Triage des RDV ======\n");
    printf("Choisir le critere de tri :\n");
    printf("1 - Par Nom\n");
    printf("2 - Par Date\n");
    printf("3 - Par Statut\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    for (int i = 0; i < compteur - 1; i++) {
        for (int j = i + 1; j < compteur; j++) {
            int condition = 0;

            switch (choix) {
                case 1: // Tri par Nom
                    condition = strcmp(rdvs[i].nom, rdvs[j].nom) > 0;
                    break;
                case 2: // Tri par Date
                    condition = strcmp(rdvs[i].date, rdvs[j].date) > 0;
                    break;
                case 3: // Tri par Statut
                    condition = strcmp(rdvs[i].status, rdvs[j].status) > 0;
                    break;
                default:
                    Afficher_Erreur("Choix invalide.\n");
                    return;
            }

            if (condition) {
                // Echange des RDVs
                RDV temp = rdvs[i];
                rdvs[i] = rdvs[j];
                rdvs[j] = temp;
            }
        }
    }

    Afficher_Message("RDVs tries avec succes.\n");

    // Afficher les RDVs tries dans un tableau
    printf("\nListe des RDVs tries :\n");
    Afficher_Message_tiri("+------------+-----------------+-----------------+-----------------+------+--------------+------------+");
    printf("| %-10s | %-15s | %-15s | %-15s | %-4s | %-12s | %-10s |\n", "Reference", "Nom", "Prenom", "Telephone", "Age", "Date", "Status");
    Afficher_Message_tiri("+------------+-----------------+-----------------+-----------------+------+--------------+------------+");
    for (int i = 0; i < compteur; i++) {
        printf("| %-10s | %-15s | %-15s | %-15s | %-4d | %-12s | %-10s |\n",
               rdvs[i].reference, rdvs[i].nom, rdvs[i].prenom, rdvs[i].telephon, rdvs[i].age, rdvs[i].date, rdvs[i].status);
    }
    Afficher_Message_tiri("+------------+-----------------+-----------------+-----------------+------+--------------+------------+");
    system("pause");
}

void Rechercher_RDV() {
    char ref[10];
    printf("Taper la reference que vous voulez rechercher : ");
    scanf("%s", ref);

    for (int i = 0; i < compteur; i++) {
        if (strcmp(rdvs[i].reference, ref) == 0) {
            printf("RDV trouve:\n");
            printf("Nom: %s, Prenom: %s, Telephone: %s, Age: %d, Date: %s, Statut: %s\n",
                   rdvs[i].nom, rdvs[i].prenom, rdvs[i].telephon, rdvs[i].age, rdvs[i].date, rdvs[i].status);
            return;
        }
    }
    Afficher_Erreur("La reference est introuvable.\n");
}

void Statistiques() {
    int valide = 0, reporte = 0, annule = 0, traite = 0;
    int age_total = 0, age_count = 0;
    int tranche_0_18 = 0, tranche_19_35 = 0, tranche_36_plus = 0;

    for (int i = 0; i < compteur; i++) {
        if (strcmp(rdvs[i].status, "valide") == 0) valide++;
        else if (strcmp(rdvs[i].status, "reporte") == 0) reporte++;
        else if (strcmp(rdvs[i].status, "annule") == 0) annule++;
        else if (strcmp(rdvs[i].status, "traite") == 0) traite++;

        // Calcul de la moyenne d'âge et des tranches d'âge
        age_total += rdvs[i].age;
        age_count++;

        if (rdvs[i].age <= 18) tranche_0_18++;
        else if (rdvs[i].age <= 35) tranche_19_35++;
        else tranche_36_plus++;
    }

    double moyenne_age = (age_count > 0) ? (double)age_total / age_count : 0;

    printf("========================= Statistiques =========================\n\n");

    printf("la moyenne d'age des patients ayant reserve : %.2f\n\n", moyenne_age);


    Afficher_Message_tiri("+-----------------+------------+------------+------------+");
    printf("| %-15s | %-10s | %-10s | %-10s |\n","Patiens", "0-18 ans", "19-35 ans", "+36");
    Afficher_Message_tiri("+-----------------+------------+------------+------------+");
    printf("| %-15s | %-10d | %-10d | %-10d |\n","Nombers", tranche_0_18, tranche_19_35, tranche_36_plus);
    Afficher_Message_tiri("+-----------------+------------+------------+------------+\n\n");

    Afficher_Message_tiri("+-----------------+------------+");
    printf("| %-15s | %-10s |\n","Statut", "Nombre");
    Afficher_Message_tiri("+-----------------+------------+");
    printf("| %-15s | %-10d |\n","valides",valide);
    printf("| %-15s | %-10d |\n","reportes",reporte);
    printf("| %-15s | %-10d |\n","annules",annule);
    printf("| %-15s | %-10d |\n","traites",traite);
    Afficher_Message_tiri("+-----------------+------------+");

    system("pause");
}

int main() {
    int choix;
    do {
        Menu_Principal();
        printf("Taper numero de votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: // Ajouter un RDV
                Ajouter_RDV();
                break;

            case 2: // Modifier ou Supprimer un RDV
                system("cls");
                printf("====== Modifier ou Supprimer un RDV ======\n");
                Modifier_Ou_Supprimer();
                break;

            case 3: // Afficher les details d'un RDV
                Afficher_RDV();
                break;

            case 4: // Trier les RDV
                Trier_RDV();
                break;

            case 5: // Rechercher un RDV
                Rechercher_RDV();
                break;

            case 6: // Statistiques
                Statistiques();
                break;

            case 7: // Quitter
                Afficher_Message("(^-^) Au revoir !!\n");
                break;

            default:
                Afficher_Erreur("(@_@) Votre choix est invalide !!\n");
                break;
        }
    } while (choix != 7);

    return 0;
}
