#pragma once
#include "Conception.h"
#include "Mappage.h"

namespace NS_Comp_Svc
{
	ref class Services
	{
	private:
		NS_Comp_Data::Conception^ oCad;
		NS_Comp_Mappage::Mappage^ oMappTB;
	public:
		Services(void);
		System::Data::DataSet^ selectionnerDonnee(System::String^ dataTableName);
		void setEtatActuel(int toSet) { this->oMappTB->SetEtatActuel(toSet); }
		void ajouterDonnee(System::String^ colonne, System::String^ valeur);
		void effacerDonnee(System::String^ colonne, System::String^ valeur);
		void updateDonnee(System::String^ colonne, System::String^ valeur, System::String^ conditionColonne, System::String^ conditionValeur);
	};
}