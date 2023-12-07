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

