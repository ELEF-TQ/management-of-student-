#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head7.h"


    int NbrEtud ; /* nombre des étudiants */
    int NbrMat; /* nombre des matiéres */
    int Nbrelem; /* nombre des éléments*/
   
   
      // LA FONCTION MAIN :
    void main(){
    	
    	printf("nombre des matieres : ");
    	scanf("%d",&NbrMat);
    	printf("nombre des elements : ");
    	scanf("%d",&Nbrelem);
    	printf("nombre des etudiants : ");
    	scanf("%d",&NbrEtud);
    	
    static T_classe personne ; 
    int id; /* le code de l'étudiant */

	saisir_donnees(&personne);  /* l'appel de fonction pour saisir les données des étudiants*/
	saisir_notes(&personne);   /* l'appel de fonction pour saisir les notes */
        
	printf("Quel etudiant vous voulez afficher son bulltein : ");
	scanf("%d",&id);
    
	afficher(personne , id) ;   /* l'appel de la fonction d'affichage */
    }

	
 
 
     // fonction pour saisir les données :
    void saisir_donnees( T_classe *pEt) {
		int i=0;
		
		 /* Remplissage des matiéres */
		printf("Remplissage des matieres : \n");
		for( i=0 ; i < NbrMat ; i++){
			printf(" le nom de la matiere %d : ",i+1 );
			scanf("%s", pEt -> mat[i].nom_matiere);
    	}
				
		printf("\n");  
		
	   	/* Remplissage des étudiants */
	   	printf("Remplissage des etudiants : \n");
		for( i=0 ; i < NbrEtud ; i++){ 
		  printf("  les informations de l\'etudiant %d :\n ",i+1);
			printf("  le Nom de l\'etudiant : ");
			scanf("%s" , pEt->etudiant[i].nom);
			printf("   le prenome de l\'etudiant : ");
			scanf("%s", pEt->etudiant[i].prenom);
			printf("   Age l\'etudiant : ");
			scanf("%ld",&pEt->etudiant[i].age);
			printf("   code de l\'etudiant : ");
			scanf("%d",&pEt->etudiant[i].code_etud);	
		}
		
		printf("\n\n"); 
		
	} // END FONCTION ;
	
	
    /*-----------------------------------------------------------------------------------------------------------*/
	
	 // fonction pour siasir les notes :
	void saisir_notes( T_classe *pEt) {
		 float sum=0; // la somme des notes des éléments
		 float moy_mat=0; // la moyenne de chaque matiére
		 int k=0; // parcourir les étudiants
		 int i=0; // parcourir les matiéres
		 int j=0; // parcourir les étements de chaque matiére
		 
		/* parcourir les etudiants*/
		for(k = 0; k < NbrEtud ; k++){
			printf(" etudiant : %s %s  \n ", pEt->etudiant[k].nom , pEt->etudiant[k].prenom );
			
			/* parcour les matriéres */
			for( i=0 ; i < NbrMat ; i++){
				printf(" >>> %s :\n",pEt -> mat[i].nom_matiere );

                /* parcourir les éléments */
				for( j=0 ; j < Nbrelem; j++){
					printf("  la note d\'element %d :",j+1);
				    scanf("%f", &pEt -> etudiant[k].note_moy[i].note_element[j]);
				    sum = sum + pEt -> etudiant[k].note_moy[i].note_element[j];
				    
	            } /* end élément */
	            
	            pEt -> etudiant[k].note_moy[i].moy = sum/Nbrelem ; /* calcul de la moyenne de chaque matiére */
	            
			} /* end matiére */
			printf("\n");
	    } /* end étudiant */
	    
	    printf("\n\n"); 
    }  // END FONCTION ;


    
    /*-----------------------------------------------------------------------------------------------------------*/
    
      // fonction d'affichage :
    void afficher( T_classe pers, int id ){
    	
    	float somElem=0;
    	float somMat=0; // la somme des moyennes des matiéres
        int k=0; // parcourir les étudiants
		int i=0; // parcourir les matiéres
		int j=0; // parcourir les étements de chaque matiére
		
        /* parcourir les etudiants*/
        for( k=0 ; k < NbrEtud ;k ++){
        	T_etud etudbult = pers.etudiant[k];
      	    if( etudbult.code_etud == id) {  /* on cherche l'étudiant avec le code qu'on a donné */
      		    printf(" \n LE BULLTEIN de \' %s %s \' \n\n", etudbult.nom , etudbult.prenom);
      		    
      		    /* parcourir les matriéres */
      	     	for( j=0 ; j < NbrMat ; j++){
      		     		N_matiere matiere = etudbult.note_moy[j]; 
      		        	printf(">>>>> %s : \n" , pers.mat[j].nom_matiere);
      		        	
      		        	/* parcourir les note des éléments */
      		            for ( k=0 ; k < Nbrelem ; k++){
      			    	printf("element %d : %.2f \n", k+1 , matiere.note_element[k]);
      			    	somElem+=matiere.note_element[k];
				        } 
				    printf("  moyenne de la matiere  : %.2f \n\n",somElem/Nbrelem );
				    somMat+=somElem/Nbrelem; /**la somme des moyenne des éléments */
				    somElem=0;
			    }
			    printf("-----------------------------------------");
			    etudbult.moy_gen = somMat/NbrMat ; /* calcul de la moyenne general */
			    printf("\n\t\t\t moyenne general : %.2f ", etudbult.moy_gen) ;
			    
		    } /* la fin de ifcondition */
	    } /* la fin de la boucle for */
	    
   }  // END FONCTION ;

