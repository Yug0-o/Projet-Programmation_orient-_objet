#include "Services.h"

NS_Comp_Svc::Services::Services(void)
{
	this->oCad = gcnew NS_Comp_Data::Conception();
		this->oMappTB = gcnew NS_Comp_Mappage::Mappage();
}
System::Data::DataSet^ NS_Comp_Svc::Services::selectionnerDonnee(System::String^ dataTableName)
{
	System::String^ sql;

	sql = this->oMappTB->Select();
	return this->oCad->getRows(sql, dataTableName);
}
void NS_Comp_Svc::Services::ajouterDonnee(System::String^ colonne, System::String^ valeur)
{

}

void NS_Comp_Svc::Services::effacerDonnee(System::String^ colonne, System::String^ valeur)
{

}

void NS_Comp_Svc::Services::updateDonnee(System::String^ colonne, System::String^ valeur, System::String^ conditionColonne, System::String^ conditionValeur)
{
	
}