#pragma once

namespace NS_Comp_Mappage
{
	ref class Mappage
	{
	private:
		System::String^ sSql;
		int etatActuel;
	public:
		System::String^ Select(void);
		System::String^ Insert(void);
		System::String^ Delete(void);
		System::String^ Update(void);
		void SetEtatActuel(int etat);
	};
}