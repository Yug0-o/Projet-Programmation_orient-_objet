#include "Mappage.h"
#include "Services.h"
#include "myForm.h"
#include <iostream>

System::Void NS_Comp_Mappage::Mappage::SetEtatActuel(int toSet) {
	this->etatActuel = toSet;
}

System::String^ NS_Comp_Mappage::Mappage::Select(void)
{
	if (this->etatActuel == 1) {
		return "SELECT * FROM [PRojet_POO].[dbo].[Personnel];";
	}
	else if (this->etatActuel == 2) {
		return "SELECT * FROM [PRojet_POO].[dbo].[Client];";
	}
	else if (this->etatActuel == 3) {
		return "SELECT * FROM [PRojet_POO].[dbo].[Commande];";
	}
	else if (this->etatActuel == 4) {
		return "SELECT * FROM [PRojet_POO].[dbo].[Produit];";
	}
}
System::String^ NS_Comp_Mappage::Mappage::Insert(void)
{
	if (this->etatActuel == 1) {
		return "INSERT INTO Personnel(" + this->colonne + ") VALUES(" + this->valeur + ");";
	}
	else if (this->etatActuel == 2) {
		return "INSERT INTO Client(" + this->colonne + ") VALUES(" + this->valeur + ");";
	}
	else if (this->etatActuel == 3) {
		return "INSERT INTO Commande(" + this->colonne + ") VALUES(" + this->valeur + ");";
	}
	else if (this->etatActuel == 4) {
		return "INSERT INTO Produit(" + this->colonne + ") VALUES(" + this->valeur + ");";
	}
}

System::String^ NS_Comp_Mappage::Mappage::Delete(void)
{
	if (this->etatActuel == 1) {
		return "DELETE FROM Personnel WHERE " + this->colonne +" = '" + this->valeur +"'; ";
	}
	else if (this->etatActuel == 2) {
		return "DELETE FROM Client WHERE " + this->colonne + " = '" + this->valeur + "'; ";
	}
	else if (this->etatActuel == 3) {
		return "DELETE FROM Commande WHERE " + this->colonne + " = '" + this->valeur + "'; ";
	}
	else if (this->etatActuel == 4) {
		return "DELETE FROM Produit WHERE " + this->colonne + " = '" + this->valeur + "'; ";
	}
}
System::String^ NS_Comp_Mappage::Mappage::Update(void)
{
	if (this->etatActuel == 1) {
		return "UPDATE Personnel SET " + this->colonne + " = '" + this->valeur + "' WHERE " + this->conditionColonne + " = '" + this->conditionValeur + "';";
	}
	else if (this->etatActuel == 2) {
		return "UPDATE Client SET " + this->colonne + " = '" + this->valeur + "' WHERE " + this->conditionColonne + " = '" + this->conditionValeur + "';";
	}
	else if (this->etatActuel == 3) {
		return "UPDATE Commande SET " + this->colonne + " = '" + this->valeur + "' WHERE " + this->conditionColonne + " = '" + this->conditionValeur + "';";
	}
	else if (this->etatActuel == 4) {
		return "UPDATE Produit SET " + this->colonne + " = '" + this->valeur + "' WHERE " + this->conditionColonne + " = '" + this->conditionValeur + "';";
	}
}



System::String^ NS_Comp_Mappage::Mappage::panier(void) {
	return "SELECT ROUND(AVG(Commande.total_ttc),2) as Panier_Moyen FROM Commande;";
};
System::String^ NS_Comp_Mappage::Mappage::affaires(void) {
	return "SELECT SUM(Commande.total_ttc) AS Chiffre_daffaires FROM Commande WHERE Commande.date_emission BETWEEN" + this->date_debut + "AND" + this->date_fin + ";";
};
System::String^ NS_Comp_Mappage::Mappage::seuil(void) {
	return "SELECT * FROM Produit WHERE Produit.quantite <= Produit.seuil_reappro; ";
};
System::String^ NS_Comp_Mappage::Mappage::montant(void) {
	return "SELECT Client.nom_client AS 'Nom', Client.prenom_client AS 'Prenom', SUM(Commande.total_ttc) AS 'Total TTC' FROM Client LEFT JOIN Commande ON Commande.id_client = Client.id_client GROUP BY Client.id_client, Client.nom_client, Client.prenom_client; ";
};
System::String^ NS_Comp_Mappage::Mappage::plus(void) {
	return "SELECT TOP (" + this->nombre +") Produit.id_produit AS 'ID_Produit', Produit.nom_produit AS 'Nom', Produit.ref_produit AS 'Ref', COALESCE(SUM(Commande.quantite_article), 0) AS Quantite_vendu FROM Commande RIGHT JOIN appartenir ON appartenir.id_commande = Commande.id_commande RIGHT JOIN Produit ON Produit.id_produit = appartenir.id_produit WHERE Commande.date_emission BETWEEN" + this->date_debut + "AND" + this->date_fin + "GROUP BY Produit.id_produit, Produit.nom_produit, Produit.ref_produit ORDER BY DESC; ";
};
System::String^ NS_Comp_Mappage::Mappage::moins(void) {
	return "SELECT TOP (" + this->nombre +") Produit.id_produit AS 'ID_Produit', Produit.nom_produit AS 'Nom', Produit.ref_produit AS 'Ref', COALESCE(SUM(Commande.quantite_article), 0) AS Quantite_vendu FROM Commande RIGHT JOIN appartenir ON appartenir.id_commande = Commande.id_commande RIGHT JOIN Produit ON Produit.id_produit = appartenir.id_produit WHERE Commande.date_emission BETWEEN " + this->date_debut + "AND" + this->date_fin + "GROUP BY Produit.id_produit, Produit.nom_produit, Produit.ref_produit ORDER BY ASC; ";
};
System::String^ NS_Comp_Mappage::Mappage::commerciale(void) {
	return "";
};
System::String^ NS_Comp_Mappage::Mappage::achat(void) {
	return "";
};
System::String^ NS_Comp_Mappage::Mappage::simu(void) {
	return "";
};

