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
		return "SELECT * FROM [PRojet_POO].[dbo].[Produits];";
	}
}
System::String^ NS_Comp_Mappage::Mappage::Insert(void)
{
	return "";
}
System::String^ NS_Comp_Mappage::Mappage::Delete(void)
{
	return "";
}
System::String^ NS_Comp_Mappage::Mappage::Update(void)
{
	return "";
}

