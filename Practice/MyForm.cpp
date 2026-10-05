#include "MyForm.h"
#include <iostream>
#include <fstream>
#include <string>
#include <json/json.h>
#include <ctime>
#include <iomanip> 
#include <locale.h>
#include <msclr\marshal_cppstd.h>


using namespace System;
using namespace System::Globalization;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Practice::MyForm form;
	Application::Run(% form);
}

double get_time_in_num(std::string date, int i) {
	std::tm dateTime = {};
	std::istringstream ss(date);
	if (i == 0) {
		ss >> std::get_time(&dateTime, "%Y-%m-%d %H:%M:%S");
	}
	else if (i == 1) {
		ss >> std::get_time(&dateTime, "%d.%m.%Y %H.%M.%S");
	}
	std::time_t time = std::mktime(&dateTime);
	return time;
}

int set_averaging(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 3600;
	}
	else if (n == 2) {
		return 10800;
	}
	else if (n == 3) {
		return 86400;
	}
}

System::Void Practice::MyForm::dalee(System::Object^ sender, System::EventArgs^ e)
{
	String^ name = comboBoxDevice->Text->ToString();
	std::string device_name = msclr::interop::marshal_as<std::string>(name);
	String^ serial = comboBoxSerial->Text->ToString();
	std::string device_serial = msclr::interop::marshal_as<std::string>(serial);
	String^ parm = comboBoxParam->Text->ToString();
	std::string param = msclr::interop::marshal_as<std::string>(parm);
	std::string file_name = "log.json";

	String^ date1 = dateTimePicker1->Value.ToString("dd/MM/yyyy hh/mm/ss");
	std::string start = msclr::interop::marshal_as<std::string>(date1);
	unsigned long start_time = get_time_in_num(start, 1);

	String^ date2 = dateTimePicker2->Value.ToString("dd/MM/yyyy hh/mm/ss");
	std::string end = msclr::interop::marshal_as<std::string>(date2);
	unsigned long end_time = get_time_in_num(end, 1);

	Json::Value root;
	Json::Reader reader;
	std::ifstream test(file_name, std::ifstream::binary);
	bool parsingSuccessful = reader.parse(test, root, false);

	int averaging = set_averaging(comboBoxAveraging->SelectedIndex);

	unsigned long first_time = 0;
	for (Json::Value::const_iterator itr1 = root.begin(); itr1 != root.end(); itr1++) {
		unsigned long time = get_time_in_num((*itr1)["Date"].asString(), 0);
		if (time > start_time) {
			if ((*itr1)["uName"].asString() == device_name && (*itr1)["serial"].asString() == device_serial) {
				first_time = time;
				break;
			}
		}
	}
	
	unsigned long current_time = first_time;
	comboBoxSerial->Items->Add(current_time);
	unsigned long long summ = 0;
	int i = 0;
	chart1->Series[0]->Points->Clear();
	this->chart1->Series->Clear();
	this->chart1->Series->Add(parm);
	for (Json::Value::const_iterator itr = root.begin(); itr != root.end(); itr++) {
		unsigned long time = get_time_in_num((*itr)["Date"].asString(), 0);
		if (time > end_time) {
			return;
		}
		if (time > start_time) {
			if (averaging > 0) {
				if ((*itr)["uName"].asString() == device_name && (*itr)["serial"].asString() == device_serial) {
					if (time < current_time + averaging) {
						std::string s = (*itr)["data"][param].asString();
						float f = 0;
						std::istringstream(s) >> f;
						summ += f;
						i += 1;
					}
					else {
						if (i == 0) { i = 1; }
						chart1->Series[0]->Points->AddXY(current_time - first_time, summ / i);
						summ = 0;
						i = 0;
						current_time = time;
					}
				}
			}
			else if (averaging == 0) {
				
				if ((*itr)["uName"].asString() == device_name && (*itr)["serial"].asString() == device_serial) {
					std::string s = (*itr)["data"][param].asString();
					float f = 0;
					std::istringstream(s) >> f;
					chart1->Series[0]->Points->AddXY(time - first_time, f);
				}
			}
		}
	}
	if (comboBoxChartType->SelectedIndex == 0) {
		chart1->Series[parm]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
	}
	else if (comboBoxChartType->SelectedIndex == 1) {
		chart1->Series[parm]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Column;
	}
	else if (comboBoxChartType->SelectedIndex == 2) {
		chart1->Series[parm]->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
	}
	return System::Void();
}

System::Void Practice::MyForm::comboBoxDevice_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e){
	comboBoxParam->Items->Clear();
	comboBoxSerial->Items->Clear();
	if (comboBoxDevice->Text == "Hydra-L") {

		comboBoxSerial->Items->AddRange(gcnew cli::array< System::Object^  >(8) { L"01", L"02", L"03", L"04", L"05", L"06", L"07", L"08"});
		comboBoxParam->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"BME280_temp", L"BME280_humidity", L"BME280_pressure" });
	}
	else if (comboBoxDevice->Text == "Паскаль") {
		comboBoxSerial->Items->AddRange(gcnew cli::array< System::Object^  >(15) { L"00", L"01", L"02", L"03", L"04", L"05", L"06", L"07", L"08", L"12", L"13", L"14", L"18", L"19", L"20"});
		comboBoxParam->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"weather_temp", L"weather_pressure" });
	}	
	else if (comboBoxDevice->Text == "РОСА К-2") {
		comboBoxSerial->Items->Add("01");
		comboBoxParam->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"weather_temp", L"weather_humidity", L"weather_pressure", L"color_tempCT", L"color_lux"});
	}
	else if (comboBoxDevice->Text == "Роса-К-1") {
		comboBoxSerial->Items->Add("01");
		comboBoxParam->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"weather_temp", L"weather_humidity", L"weather_pressure", L"color_tempCT", L"color_lux" });
	}
	else if (comboBoxDevice->Text == "Тест Студии") {
		comboBoxSerial->Items->Add("schHome");
		comboBoxParam->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"BME280_temp", L"BME280_humidity", L"BME280_pressure", L"BMP280_temp", L"BMP280_pressure"});
	}


	//else if (comboBoxDevice->Text == "Опорный барометр") {
	//	comboBoxSerial->Items->Add("01");
	//}
	//else if (comboBoxDevice->Text == "Сервер dbrobo") {
	//	comboBoxSerial->Items->Add("01");
	//}
	//else if (comboBoxDevice->Text == "Сервер webrobo") {
	//	comboBoxSerial->Items->Add("01");
	//}
	//else if (comboBoxDevice->Text == "Сервер rstring") {
	//	comboBoxSerial->Items->Add("01");
	//}
	//else if (comboBoxDevice->Text == "Сервер dokuwiki") {
	//	comboBoxSerial->Items->Add("01");
	//}
	//else if (comboBoxDevice->Text == "Сервер СЕВ") {
	//	comboBoxSerial->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"01", L"02", L"03" });
	//}
}
