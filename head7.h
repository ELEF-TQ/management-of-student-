#ifndef HEAD7_H_INCLUDED
#define HEAD7_H_INCLUDED

typedef struct{
        char nom_matiere[20] ;
        float note_element[3]; 
		float moy;
	} N_matiere;

	typedef struct{
		char nom[10];
		char prenom[10];
	    short int age ; 
		int  code_etud;
		N_matiere note_moy[6] ;
		float moy_gen;
	} T_etud;

	typedef struct{
		N_matiere mat[6];
		T_etud etudiant[3];
	} T_classe;

	void saisir_donnees( T_classe *pEt) ;
	void saisir_notes( T_classe *pEt) ;
	void afficher( T_classe pers, int id) ;

#endif // HEAD7_H_INCLUDED




