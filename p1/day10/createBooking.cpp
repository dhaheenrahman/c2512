/**
 * @brief Creates a new booking.
 * @param bookingId Array of booking IDs.
 * @param ticketAmount Array of ticket amounts.
 * @param foodAmount Array of food amounts.
 * @param bookingsCounter Current number of bookings.
 */


void createBooking(int bookingId[], int ticketAmount[], int foodAmount[], int &bookingsCounter) {
    // Checking whether the booking limit is exceeeded
	if (bookingsCounter >= MAX_SIZE) {                           
		cout << "Booking Limit exceeded!";
		return;
	}

	int id;

	cout << "Enter Booking Id: ";
	cin >> id;
    // Checking if the id is a positive value
	if (id <= 0) {           
        		cout << "Enter valid Booking ID.";
	}
	else {
		// Checking if the entered id is already existing                                      
		if(ifExist(id, bookingId, bookingsCounter) != -1 ) {    
			cout << "Booking Id already exists!";                         
		}
		else {
			int amountOfTicket,amountOfFood;

            // Read the ticket amount and food amount once the id is validated
			cout << "Enter Ticket amount: ";                    
			cin >> amountOfTicket;
			cout << "Enter Food amount: ";
			cin >> amountOfFood;

            // Insert the values to each array
			bookingId[bookingsCounter] = id;                    
			ticketAmount[bookingsCounter] = amountOfTicket;
			foodAmount[bookingsCounter] = amountOfFood;

			cout << "Booking added successfully..";            

			bookingsCounter++ ;     
		}
	}

	cout << "\n";
}