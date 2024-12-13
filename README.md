# Parklink - Smart Parking Solution

###Figma Link: https://www.figma.com/proto/PDbDVaKjTM6jBVKj36oQok/Untitled?node-id=0-1&t=0AN0eRTxicw9sibS-1

Parklink is an IoT-based smart parking management system designed to tackle urban parking challenges, particularly in rapidly developing countries like India. By integrating IoT technologies, real-time monitoring, and user-centric interfaces, Parklink aims to reduce congestion, improve traffic flow, and support sustainable urban development.

## Features

### User Features
- **Real-time Parking Availability:** View available parking spots instantly.
- **Booking System:** Pre-book your parking slot for convenience.
- **Navigation Integration:** Navigate to parking locations using Google Maps.
- **Wallet System:** Simplified payments through an integrated wallet.
- **Vehicle Dashboard:** Track parking history and expenses.

### Service Provider Features
- **Dashboard Insights:** Access statistics, earnings, and maintenance requests.
- **Parking Lot Management:** Add and monitor parking lots with ease.
- **Admin Panel:** Ensure smooth onboarding and verification of parking spaces.

## Tech Stack
- **Hardware:**
  - ESP32 microcontroller for processing sensor data and server communication.
  - Ultrasonic sensors for vehicle detection.
- **Backend:** Node.js with MySQL database.
- **Frontend:** React.js for dynamic user interfaces.
- **Tools:**
  - Figma for UI/UX design.
  - Postman for API testing.
  - Google Maps API for navigation.

## System Overview
1. **IoT-Enabled Sensors:** Ultrasonic sensors detect vehicle presence and send real-time data to the server.
2. **Centralized Server:** Processes data and updates the parking slot statuses.
3. **User Dashboard:** Displays parking layouts, booking options, and navigation assistance.
4. **Service Provider Dashboard:** Provides insights into parking lot operations and earnings.

## Advantages
- **Efficiency:** Reduces time spent searching for parking.
- **Scalability:** Supports diverse environments, from small lots to multi-level facilities.
- **Sustainability:** Reduces fuel consumption and emissions by minimizing idle time.

## Challenges
- **Connectivity Issues:** Requires stable internet for real-time updates.
- **Infrastructure Gaps:** Limited infrastructure in some regions may hinder deployment.
- **Initial Costs:** Setup costs could be a barrier in cost-sensitive markets.

## Future Scope
- **Mobile Application:** Enable bookings and monitoring on-the-go.
- **Number Plate Recognition:** Automate vehicle detection and billing.
- **Advanced Analytics:** Gain insights into user behavior and parking trends.
- **Fast Tag Integration:** Streamline payment processes for Fast Tag-equipped vehicles.
- **What3Words Integration:** Provide precise navigation to parking spots.

## Getting Started

### Prerequisites
- ESP32 microcontroller and ultrasonic sensors.
- Node.js runtime environment.
- MySQL database.

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/nilaMan16/Parklink.git
   ```
2. Navigate to the project directory and install dependencies:
   ```bash
   cd Parklink
   npm install
   ```
3. Set up the database:
   - Import the provided MySQL schema.
   - Update database credentials in the backend configuration file.
4. Start the server:
   ```bash
   npm start
   ```
5. Access the application in your browser at `http://localhost:3000`.

## Contributing
Contributions are welcome! Please fork the repository, create a new branch, and submit a pull request for review.

## License
This project is licensed under the MIT License.

## References
- [ESP32 Documentation](https://www.espressif.com/en/products/socs/esp32)
- [ReactJS Documentation](https://react.dev)
- [Google Maps API](https://developers.google.com/maps/documentation)
- [MySQL Documentation](https://dev.mysql.com/doc/)

## Acknowledgements
This project was developed by Jintu Nath, Mrinmoy Shyam, Nilakhya Mandita Bordoloi, and Parag Choudhury as part of their 7th-semester coursework at Jorhat Engineering College, Assam.

---
For more details, visit the [GitHub Repository](https://github.com/nilaMan16/Parklink).
