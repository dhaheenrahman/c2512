/**
 * @brief Creates a new booking.
 * @param bookingId Array of booking IDs.
 * @param ticketAmount Array of ticket amounts.
 * @param foodAmount Array of food amounts.
 * @param bookingsCounter Current number of bookings.
 */


void createBooking(int bookingId[], int ticketAmount[], int foodAmount[], int &bookingsCounter) {

	if (bookingsCounter >= MAX_SIZE) {                           // checking whether the booking limit is exceeeded
		cout << "Booking Limit exceeded!";
		return;
	}

	int id;

	cout << "Enter Booking Id: ";
	cin >> id;
	if (id>0) {                                                 // checking if the id is a positive value
		if(ifExist(id, bookingId, bookingsCounter) == -1 ) {    // checking if the entered id is already existing
			int amountOfTicket,amountOfFood;

			cout << "Enter Ticket amount: ";                    // read the ticket amount and food amount once the id is validated
			cin >> amountOfTicket;
			cout << "Enter Food amount: ";
			cin >> amountOfFood;

			bookingId[bookingsCounter] = id;                    // insert the values to each array
			ticketAmount[bookingsCounter] = amountOfTicket;
			foodAmount[bookingsCounter] = amountOfFood;

			cout << "Booking added successfully..";            

			bookingsCounter++ ;                                 //
		}
		else {
			cout << "Booking Id already exists!";               
		}
	}
	else {
		cout << "Enter valid Booking ID.";
	}
	cout << "\n";
}
