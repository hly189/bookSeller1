#pragma once
#include "InventoryDatabase.h"
#include "Helpers.h"
#include "pch.h"
#include "Date.h"
#include <fstream>
#include <string>
#include <iostream>

class ReportModule
{
private:
	Book* Books;
	std::string information;
	int menu;
	int bookcount;
	InventoryDatabase &currentInventori;


public:
	ReportModule(); 
	ReportModule(InventoryDatabase& currentInventori);
	void ReportMainMenu(InventoryDatabase& currentInventori);
	void ReportInventoryList(InventoryDatabase& currentInventori);
	void ReportWholeSaleValue(InventoryDatabase& currentInventori);
	void ReportRetailValue(InventoryDatabase& currentInventori);
	void ReportListByQuantity(InventoryDatabase& currentInventori);
	void ReportListByCost(InventoryDatabase& currentInventori);
	void ReportListByAge(InventoryDatabase& currentInventori);;
};