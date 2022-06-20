#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head7.h"


    int NbrEtud ; /* nombre des �tudiants */
    int NbrMat; /* nombre des mati�res */
    int Nbrelem; /* nombre des �l�ments*/
   
   
      // LA FONCTION MAIN :
    void main(){
    	
    	printf("nombre des matieres : ");
    	scanf("%d",&NbrMat);
    	printf("nombre des elements : ");
    	scanf("%d",&Nbrelem);
    	printf("nombre des etudiants : ");
    	scanf("%d",&NbrEtud);
    	
    static T_classe personne ; 
    int id; /* le code de l'�tudiant */

	saisir_donnees(&personne);  /* l'appel de fonction pour saisir les donn�es des �tudiants*/
	saisir_notes(&personne);   /* l'appel de fonction pour saisir les notes */
        
	printf("Quel etudiant vous voulez afficher son bulltein : ");
	scanf("%d",&id);
    
	afficher(personne , id) ;   /* l'appel de la fonction d'affichage */
    }

	
 
 
     // fonction pour saisir les donn�es :
    void saisir_donnees( T_classe *pEt) {
		int i=0;
		
		 /* Remplissage des mati�res */
		printf("Remplissage des matieres : \n");
		for( i=0 ; i < NbrMat ; i++){
			printf(" le nom de la matiere %d : ",i+1 );
			scanf("%s", pEt -> mat[i].nom_matiere);
    	}
				
		printf("\n");  
		
	   	/* Remplissage des �tudiants */
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
		 float sum=0; // la somme des notes des �l�ments
		 float moy_mat=0; // la moyenne de chaque mati�re
		 int k=0; // parcourir les �tudiants
		 int i=0; // parcourir les mati�res
		 int j=0; // parcourir les �tements de chaque mati�re
		 
		/* parcourir les etudiants*/
		for(k = 0; k < NbrEtud ; k++){
			printf(" etudiant : %s %s  \n ", pEt->etudiant[k].nom , pEt->etudiant[k].prenom );
			
			/* parcour les matri�res */
			for( i=0 ; i < NbrMat ; i++){
				printf(" >>> %s :\n",pEt -> mat[i].nom_matiere );

                /* parcourir les �l�ments */
				for( j=0 ; j < Nbrelem; j++){
					printf("  la note d\'element %d :",j+1);
				    scanf("%f", &pEt -> etudiant[k].note_moy[i].note_element[j]);
				    sum = sum + pEt -> etudiant[k].note_moy[i].note_element[j];
				    
	            } /* end �l�ment */
	            
	            pEt -> etudiant[k].note_moy[i].moy = sum/Nbrelem ; /* calcul de la moyenne de chaque mati�re */
	            
			} /* end mati�re */
			printf("\n");
	    } /* end �tudiant */
	    
	    printf("\n\n"); 
    }  // END FONCTION ;


    
    /*-----------------------------------------------------------------------------------------------------------*/
    
      // fonction d'affichage :
    void afficher( T_classe pers, int id ){
    	
    	float somElem=0;
    	float somMat=0; // la somme des moyennes des mati�res
        int k=0; // parcourir les �tudiants
		int i=0; // parcourir les mati�res
		int j=0; // parcourir les �tements de chaque mati�re
		
        /* parcourir les etudiants*/
        for( k=0 ; k < NbrEtud ;k ++){
        	T_etud etudbult = pers.etudiant[k];
      	    if( etudbult.code_etud == id) {  /* on cherche l'�tudiant avec le code qu'on a donn� */
      		    printf(" \n LE BULLTEIN de \' %s %s \' \n\n", etudbult.nom , etudbult.prenom);
      		    
      		    /* parcourir les matri�res */
      	     	for( j=0 ; j < NbrMat ; j++){
      		     		N_matiere matiere = etudbult.note_moy[j]; 
      		        	printf(">>>>> %s : \n" , pers.mat[j].nom_matiere);
      		        	
      		        	/* parcourir les note des �l�ments */
      		            for ( k=0 ; k < Nbrelem ; k++){
      			    	printf("element %d : %.2f \n", k+1 , matiere.note_element[k]);
      			    	somElem+=matiere.note_element[k];
				        } 
				    printf("  moyenne de la matiere  : %.2f \n\n",somElem/Nbrelem );
				    somMat+=somElem/Nbrelem; /**la somme des moyenne des �l�ments */
				    somElem=0;
			    }
			    printf("-----------------------------------------");
			    etudbult.moy_gen = somMat/NbrMat ; /* calcul de la moyenne general */
			    printf("\n\t\t\t moyenne general : %.2f ", etudbult.moy_gen) ;
			    
		    } /* la fin de ifcondition */
	    } /* la fin de la boucle for */
	    
   }  // END FONCTION ;

