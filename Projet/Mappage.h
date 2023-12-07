#pragma once

namespace NS_Comp_Mappage
{
	ref class Mappage
	{
	private:
		System::String^ sSql;

		System::String^ colonne;
		System::String^ valeur;
		System::String^ conditionColonne;
		System::String^ conditionValeur;

		static int etatActuel = 0;
	public:
		System::String^ Select(void);
		System::String^ Insert(void);
		System::String^ Delete(void);
		System::String^ Update(void);
		static int GetEtatActuel()
		{
			return etatActuel;
		}
		void SetEtatActuel(int etat);
		void NS_Comp_Mappage::Mappage::setColonne(System::String^ colonne)
		{
			this->colonne = colonne;
		}
		void NS_Comp_Mappage::Mappage::setValeur(System::String^ valeur)
		{
			this->valeur = valeur;
		}
		void NS_Comp_Mappage::Mappage::setConditionColonne(System::String^ conditionColonne)
		{
			this->conditionColonne = conditionColonne ;
		}
		void NS_Comp_Mappage::Mappage::setConditionValeur(System::String^ conditionValeur)
		{
			this->conditionValeur = conditionValeur ;
		}
		System::String^ NS_Comp_Mappage::Mappage::getColonne(void) { return this->colonne; }
		System::String^ NS_Comp_Mappage::Mappage::getValeur(void) { return this->valeur; }
		System::String^ NS_Comp_Mappage::Mappage::getConditionColonne(void) { return this->conditionColonne; }
		System::String^ NS_Comp_Mappage::Mappage::getConditionValeur(void) { return this->conditionValeur; }
	};
}