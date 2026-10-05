# IoT Sensor Telemetry Analytics App

A desktop application designed for parsing, processing, and visualizing data from environmental telemetry sensors deployed across university classrooms. Built using C++/CLI and Windows Forms.

## Key Features
* **JSON Log Parsing:** Automatically reads and parses large `log.json` files containing device metrics via the `jsoncpp` library.
* **Smart Data Averaging:** Features time-based data aggregation (hourly, 3-hour, or daily blocks) to smooth out sensor fluctuations.
* **Dynamic Visualization:** Renders interactive charts (Splines, Columns, or Points) using the `Windows.Forms.DataVisualization` library.
* **Device Support:** Pre-configured presets for popular university monitoring hardware including:
  * **Hydra-L** (Temperature, Humidity, Pressure)
  * **Паскаль** (Temperature, Pressure)
  * **РОСА К-2 / Роса-К-1** (Temperature, Humidity, Pressure, Color Temp, Lux)
  * **Тест Студии** (Dual BME280/BMP280 sensor matrix)

## Tech Stack
* **Language:** C++/CLI (Managed C++)
* **Framework:** .NET Framework / Windows Forms
* **Libraries:** jsoncpp (JSON parsing), msclr (data marshaling)

## Core Analytics Logic
The system processes data chronologically based on user-defined time windows (`dateTimePicker`). It filters telemetry by `uName` and `serial`, averages the float metrics if requested, and maps the timeline onto an X-Y axis relative to the initial timestamp.
