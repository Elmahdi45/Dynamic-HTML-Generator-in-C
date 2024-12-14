#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void ajouter_cartes(FILE *html) {
    int num_cards, num_items; //Hna htit chhal bghit mn card o chhal mn element f kola card
    char item[50];//L item li ydkhl l utilisateur (chbgha ykon f lcard)
    char color[20];// color bach ybdl 3la hsab chbgha
    int width, height; // sizes (machi f css ghir basic html)
    int  i;
    
    printf("Combien de cartes vous voulez ajoutez ?");
    scanf("%d", &num_cards);
    getchar();//msh line lkher

    printf("Enter le width");
    scanf("%d", &width);
    getchar();

    printf("Entrer le height");
    scanf("%d", &height);
    getchar();

    printf("Entrez la couleur des cartes!");
    fgets(color, sizeof(color), stdin);
    color[strcspn(color, "\n")] = 0;

    fprintf(html, "<div class=\"card-container\">\n");

    for ( i = 0; i < num_cards; i++) {
        fprintf(html, "<div class=\"card\" style=\"background-color: %s; width: %dpx; height: %dpx;\">\n", color, width, height);
        //kola card kangad lha width color height dialha b les classes f html.(3la hsab chhal mn card)
        fprintf(html, "<ul>\n");

        printf("Combien des elements dans la carte %d? ", i + 1);
        scanf("%d", &num_items);
        getchar();

        for (int j = 0; j < num_items; j++) {
            printf("Enter l element%d pour la carte %d: ", j + 1, i + 1);
            fgets(item, sizeof(item), stdin);//fgets better than scanf hna hit ez nkhdm biha 
            item[strcspn(item, "\n")] = 0;
            fprintf(html, "<li>%s</li>\n", item);//list d lcard
        }

        fprintf(html, "</ul>\n");
        fprintf(html, "</div>\n");
    }

    fprintf(html, "</div>\n");
}

void ajouter_section(FILE *html) {
    char section_title[50], section_content[500];
    char bg_color[20], title_color[20], text_color[20];
    char repeat_choice = 'o'; 
    int choix_content = 0;

    
    printf("Entrez le titre de la section : ");
    fgets(section_title, sizeof(section_title), stdin);
    section_title[strcspn(section_title, "\n")] = 0;

    printf("Entrez la couleur de background de la section : ");
    fgets(bg_color, sizeof(bg_color), stdin);
    bg_color[strcspn(bg_color, "\n")] = 0;

    printf("Entrez la couleur du titre de la section : ");
    fgets(title_color, sizeof(title_color), stdin);
    title_color[strcspn(title_color, "\n")] = 0;

    printf("Entrez la couleur du texte de la section : ");
    fgets(text_color, sizeof(text_color), stdin);
    text_color[strcspn(text_color, "\n")] = 0;

   
    fprintf(html, "<section style=\"background-color: %s; padding: 20px; margin: 10px; border-radius: 8px;\">\n", bg_color);
    fprintf(html, "  <h2 style=\"color: %s;\">%s</h2>\n", title_color, section_title);

   
    do {
        printf("\nQue voulez-vous ajouter à la section ?\n");
        printf("1. Paragraphe\n2. Liste\n3. Image\n");
        printf("Votre choix : ");
        scanf("%d", &choix_content);
        getchar(); 

        if (choix_content == 1) {
           
            printf("Entrez le contenu du paragraphe : ");
            fgets(section_content, sizeof(section_content), stdin);
            section_content[strcspn(section_content, "\n")] = 0;
            fprintf(html, "  <p style=\"color: %s;\">%s</p>\n", text_color, section_content);

        } else if (choix_content == 2) {
            
            int num_items;
            char item[100];

            printf("Combien d'elements dans la liste ? ");
            scanf("%d", &num_items);
            getchar();

            fprintf(html, "  <ul style=\"color: %s;\">\n", text_color);
            for (int i = 0; i < num_items; i++) {
                printf("Entrez l'element %d : ", i + 1);
                fgets(item, sizeof(item), stdin);
                item[strcspn(item, "\n")] = 0;
                fprintf(html, "    <li>%s</li>\n", item);
            }
            fprintf(html, "  </ul>\n");

        } else if (choix_content == 3) {
            // Add an image
            char image_url[200];
            int image_width, image_height;

            printf("Entrez l'URL de l'image : ");
            fgets(image_url, sizeof(image_url), stdin);
            image_url[strcspn(image_url, "\n")] = 0;

            printf("Entrez la largeur de l'image (en pixels) : ");
            scanf("%d", &image_width);
            getchar();

            printf("Entrez la hauteur de l'image (en pixels) : ");
            scanf("%d", &image_height);
            getchar();

            fprintf(html, "  <img src=\"%s\" alt=\"Image de la section\" style=\"width:%dpx; height:%dpx; border-radius: 8px;\" />\n", 
                    image_url, image_width, image_height);
        } else {
            printf("Choix non valide.\n");
        }

      
        printf("Voulez-vous ajouter autre chose à cette section ? (o/n) : ");
        scanf(" %c", &repeat_choice);
        getchar(); //

    } while (repeat_choice == 'o');

    
    fprintf(html, "</section>\n");
}

//styling links dial navbar!!

void ajouter_link_style(FILE *html) {
    char link_color[20], font_family[50];
    printf("Entrez la couleur des liens de la navbar");
    fgets(link_color, sizeof(link_color), stdin);
    link_color[strcspn(link_color, "\n")] = 0; 

    
    printf("Entrez le style de texte! ");
    fgets(font_family, sizeof(font_family), stdin);
    font_family[strcspn(font_family, "\n")] = 0;

    //styles 3la hsab l user chno khtar!
    fprintf(html, "<style>\n");
    fprintf(html, "nav ul li a {\n");
    fprintf(html, "    color: %s;\n", link_color);
    fprintf(html, "    font-family: '%s';\n", font_family);
    fprintf(html, "}\n");

    //lhover effect !
    fprintf(html, "nav ul li a:hover {\n");
    fprintf(html, "    color: #FFD700; \n");
    fprintf(html, "}\n");
    fprintf(html, "</style>\n");
}
void ajouter_navbar_color(FILE *html) {
    char color[20];
    printf("Entrez la couleur de fond de la navbar  ");
    fgets(color, sizeof(color), stdin);
    color[strcspn(color, "\n")] = 0;

    fprintf(html, "<style>\nnav { background-color: %s; }\n</style>\n", color);
}

void ajouter_background_image(FILE *html) {
    char background_image[200];

    printf("Entrez le chemin ou l'URL de l'image de fond : ");
    fgets(background_image, sizeof(background_image), stdin);
    background_image[strcspn(background_image, "\n")] = 0; 

    fprintf(html, "<style>\n");
    fprintf(html, "body {\n");
    fprintf(html, "    background-image: url('%s');\n", background_image);
    fprintf(html, "    background-size: cover;\n");
    fprintf(html, "    background-position: center;\n");
    fprintf(html, "    background-attachment: fixed;\n");
    fprintf(html, "    margin: 0;\n");
    fprintf(html, "    padding: 0;\n");
    fprintf(html, "}\n");
    fprintf(html, "</style>\n");
}



void ajouter_navbar(FILE *html) {
    char lien[100];
    int num_links = 0;
    char title[20];
    int choixEditTitre;
    int tailleH1 = 1;
    char position;
    char choixAlignementNavbar;
    char nav_class[20] = "left-align";
    fprintf(html, "<!DOCTYPE html>\n<html>\n<head>\n");
    fprintf(html, "<link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\">\n");
    fprintf(html, "<link rel=\"stylesheet\" href=\"https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.7.1/css/all.min.css\">\n");
    fprintf(html, "<title>Website</title>\n");
    fprintf(html, "</head>\n<body>\n");

    
    printf("Entrez le titre que vous voulez dans la navbar : ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = 0; 
    printf("Voulez-vous éditer ce titre ? o/n : ");
    scanf(" %c", &choixEditTitre);
    getchar(); 

    char title_color[20];
    if (choixEditTitre == 'o') {
        printf("Choisissez la taille du titre (1 pour <h1>, 6 pour <h6>) : ");
        scanf("%d", &tailleH1);
        if (tailleH1 < 1 || tailleH1 > 6) {
            printf("Taille invalide. La taille par défaut <h1> sera utilisée.\n");
            tailleH1 = 1;
        }
        getchar(); 

        printf("Choisissez la position du titre ('g'=gauche, 'c'=centre, 'd'=droite) : ");
        scanf(" %c", &position);
        getchar(); 

       

        if (position == 'g') {
            strcpy(nav_class, "left-align");
        } else if (position == 'd') {
            strcpy(nav_class, "right-align");
        } else if (position == 'c') {
            strcpy(nav_class, "center-align");
        }

    }

    
    printf("Combien de liens voulez-vous dans la navbar ? ");
    scanf("%d", &num_links);
    getchar();  

    
    printf("Alignez vos liens dans la navbar ('g'=gauche, 'c'=centre, 'd'=droite) : ");
    scanf(" %c", &choixAlignementNavbar);
    getchar();

    
    if (choixAlignementNavbar == 'g') {
        strcpy(nav_class, "left-align");
    } else if (choixAlignementNavbar == 'd') {
        strcpy(nav_class, "right-align");
    } else if (choixAlignementNavbar == 'c') {
        strcpy(nav_class, "center-align");
    }

    
    if (choixEditTitre == 'o') {
        fprintf(html, "<h%d id=\"navbar-title\" class=\"%s\">%s</h%d>\n", tailleH1, nav_class, title, tailleH1);
    } else {
        fprintf(html, "<h1 id=\"navbar-title\" class=\"%s\">%s</h1>\n", nav_class, title);
    }

   
    fprintf(html, "<nav class=\"%s\">\n", nav_class);
    fprintf(html, "  <div class=\"navbar-content\">\n");
    fprintf(html, "    <ul>\n");

    
    for(int i = 0; i < num_links; i++) {
        printf("Entrez le nom du lien %d : ", i + 1);
        fgets(lien, sizeof(lien), stdin);
        lien[strcspn(lien, "\n")] = 0; 
        fprintf(html, "      <li><a href=\"#%s\">%s</a></li>\n", lien, lien);
    }

    fprintf(html, "    </ul>\n");
    fprintf(html, "  </div>\n");
    fprintf(html, "</nav>\n");

    fprintf(html, "</body>\n</html>");
}
void ajouter_footer(FILE *html) {
    char text[100];
    char background_color[20];
    char text_color[20];
    char choice_icon;
    int num_icons;

    // Entrez le contenu du footer
    printf("Entrez le contenu du footer : ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; // Supprime le '\n'

    // Entrez les couleurs du footer
    printf("Entrez la couleur de fond du footer : ");
    fgets(background_color, sizeof(background_color), stdin);
    background_color[strcspn(background_color, "\n")] = 0;

    printf("Entrez la couleur du texte du footer : ");
    fgets(text_color, sizeof(text_color), stdin);
    text_color[strcspn(text_color, "\n")] = 0;

    // Ajout des icônes
    printf("Ajoutez des icônes ? ('o' pour oui, 'n' pour non) : ");
    scanf(" %c", &choice_icon);

    // Écrire le début du footer dans le fichier HTML
    fprintf(html, "<footer style=\"background-color:%s; color:%s; \">\n", background_color, text_color);
    fprintf(html, "    <p>%s</p>\n", text);

    if (choice_icon == 'o') {
        fprintf(html, "    <div class=\"social-icons\">\n");

        printf("Quelles icônes souhaitez-vous ajouter ? ('f': Facebook, 'i': Instagram, 'w': WhatsApp, 'x': Twitter, 'q': Quitter)\n");

        while (1) {
            scanf(" %c", &choice_icon);
            if (choice_icon == 'q') break;

            switch (choice_icon) {
                case 'f':
                    fprintf(html, "        <a href=\"https://facebook.com\" target=\"_blank\" aria-label=\"Facebook\">\n");
                    fprintf(html, "            <i class=\"fa-brands fa-facebook\"></i>\n");
                    fprintf(html, "        </a>\n");
                    break;
                case 'i':
                    fprintf(html, "        <a href=\"https://instagram.com\" target=\"_blank\" aria-label=\"Instagram\">\n");
                    fprintf(html, "            <i class=\"fa-brands fa-instagram\"></i>\n");
                    break;
                case 'w':
                    fprintf(html, "        <a href=\"https://whatsapp.com\" target=\"_blank\" aria-label=\"WhatsApp\">\n");
                    fprintf(html, "            <i class=\"fa-brands fa-whatsapp\"></i>\n");
                    break;
                case 'x':
                    fprintf(html, "        <a href=\"https://twitter.com\" target=\"_blank\" aria-label=\"Twitter\">\n");
                    fprintf(html, "            <i class=\"fa-brands fa-twitter\"></i>\n");
                    break;
                default:
                    printf("Option invalide. Veuillez choisir parmi 'f', 'i', 'w', 'x', ou 'q'.\n");
                    break;
            }
        }

        fprintf(html, "    </div>\n"); 
    }

    // Fin du footer
    fprintf(html, "</footer>\n");
}


int main() {
    int choix = 0;
    char continuer = 'o';
    FILE *html = fopen("page.html", "w");
    fprintf(html, "<!DOCTYPE html>\n<html>\n<head>\n");
    fprintf(html, "<title>Website</title>\n");
    fprintf(html, "</head>\n<body>\n");
    if (choix == 2) {
    ajouter_background_image(html);
}
    if (html == NULL) {
        printf("Erreur lors de la création du fichier.\n");
        return 1;
    }

    while (continuer == 'o') {
        printf("Que souhaitez-vous ajouter à votre page HTML?\n");
        printf("1. Titre et Navbar\n");
        printf("2.Background\n");
        printf("3.Ajoutez couleur background navbar\n ");
        printf("4.Changer style liens navbar\n");
        printf("5.Ajouter section!\n");
        printf("6.list cards\n");
        printf("7.Ajoutez footer\n\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        getchar(); 

        if (choix==1) {
            ajouter_navbar(html);
        } 
        else if (choix==2)
        {
            ajouter_background_image(html);
        }
        else if (choix==3)
        {
            ajouter_navbar_color(html);
        }
        else if (choix==4)
        {
             ajouter_link_style(html);
        }
        else if (choix == 5)
        {
           ajouter_section(html);
        }
        else if (choix==6)
        {
            ajouter_cartes(html);
        }
        else if (choix == 7) {
            ajouter_footer(html);
        }
        
        
        else {
            printf("Option non valide.\n");
        }

        printf(" continuer ? (o/n) : ");
        scanf(" %c", &continuer);
        getchar(); 
    }

    fclose(html);
    
    return 0;
}
