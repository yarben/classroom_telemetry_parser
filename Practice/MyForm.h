#pragma once

namespace Practice {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ comboBoxDevice;


	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::ComboBox^ comboBoxParam;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ comboBoxSerial;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ComboBox^ comboBoxAveraging;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::ComboBox^ comboBoxChartType;

	protected:

	protected:

	protected:

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBoxDevice = (gcnew System::Windows::Forms::ComboBox());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->comboBoxParam = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBoxSerial = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->comboBoxAveraging = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->comboBoxChartType = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(126, 538);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(106, 59);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Далее";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::dalee);
			// 
			// comboBoxDevice
			// 
			this->comboBoxDevice->FormattingEnabled = true;
			this->comboBoxDevice->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"Hydra-L", L"Паскаль", L"Роса-К-1", L"РОСА К-2",
					L"Сервер СЕВ", L"Тест Студии", L"Опорный барометр", L"Сервер dokuwiki", L"Сервер dbrobo", L"Сервер webrobo"
			});
			this->comboBoxDevice->Location = System::Drawing::Point(126, 116);
			this->comboBoxDevice->Name = L"comboBoxDevice";
			this->comboBoxDevice->Size = System::Drawing::Size(271, 33);
			this->comboBoxDevice->TabIndex = 1;
			this->comboBoxDevice->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBoxDevice_SelectedIndexChanged);
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(676, 84);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(953, 438);
			this->chart1->TabIndex = 2;
			this->chart1->Text = L"chart1";
			// 
			// comboBoxParam
			// 
			this->comboBoxParam->FormattingEnabled = true;
			this->comboBoxParam->Location = System::Drawing::Point(126, 228);
			this->comboBoxParam->Name = L"comboBoxParam";
			this->comboBoxParam->Size = System::Drawing::Size(253, 33);
			this->comboBoxParam->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(120, 72);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(225, 31);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Выберите прибор:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(120, 184);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(375, 31);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Выберите параметр измерения:";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(126, 340);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(219, 31);
			this->dateTimePicker1->TabIndex = 6;
			this->dateTimePicker1->Value = System::DateTime(2023, 2, 23, 12, 0, 0, 0);
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Location = System::Drawing::Point(410, 340);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(219, 31);
			this->dateTimePicker2->TabIndex = 7;
			this->dateTimePicker2->Value = System::DateTime(2023, 2, 24, 12, 0, 0, 0);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(120, 292);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(103, 31);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Начало:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(404, 292);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(91, 31);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Конец:";
			// 
			// comboBoxSerial
			// 
			this->comboBoxSerial->FormattingEnabled = true;
			this->comboBoxSerial->Location = System::Drawing::Point(439, 116);
			this->comboBoxSerial->Name = L"comboBoxSerial";
			this->comboBoxSerial->Size = System::Drawing::Size(133, 33);
			this->comboBoxSerial->TabIndex = 10;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(433, 72);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(90, 31);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Серия:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(120, 404);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(141, 31);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Осреднять:";
			// 
			// comboBoxAveraging
			// 
			this->comboBoxAveraging->FormattingEnabled = true;
			this->comboBoxAveraging->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Не осреднять", L"Осреднять за час", L"Осреднять за каждые 3 часа",
					L"Осреднять за сутки"
			});
			this->comboBoxAveraging->Location = System::Drawing::Point(126, 449);
			this->comboBoxAveraging->Name = L"comboBoxAveraging";
			this->comboBoxAveraging->Size = System::Drawing::Size(185, 33);
			this->comboBoxAveraging->TabIndex = 13;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(404, 404);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(164, 31);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Тип графика:";
			// 
			// comboBoxChartType
			// 
			this->comboBoxChartType->FormattingEnabled = true;
			this->comboBoxChartType->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Spline", L"Column", L"Points" });
			this->comboBoxChartType->Location = System::Drawing::Point(410, 449);
			this->comboBoxChartType->Name = L"comboBoxChartType";
			this->comboBoxChartType->Size = System::Drawing::Size(162, 33);
			this->comboBoxChartType->TabIndex = 15;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1755, 649);
			this->Controls->Add(this->comboBoxChartType);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->comboBoxAveraging);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->comboBoxSerial);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->dateTimePicker2);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBoxParam);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->comboBoxDevice);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"Погода МФ МГТУ";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void dalee(System::Object^ sender, System::EventArgs^ e);
	private: System::Void comboBoxDevice_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
};
}
