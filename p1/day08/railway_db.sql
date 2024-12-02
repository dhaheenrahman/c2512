CREATE TABLE passenger (
        passenger_id NUMBER PRIMARY KEY,
        passenger_name VARCHAR2(100) NOT NULL,
        passenger_age NUMBER NOT NULL
    );

CREATE TABLE train (
    train_id NUMBER PRIMARY KEY,
    train_name VARCHAR2(100) NOT NULL,
    route VARCHAR2(255) NOT NULL
);

CREATE TABLE train_seat (
        seat_id NUMBER PRIMARY KEY,
        seat_number VARCHAR2(10) NOT NULL,
        class VARCHAR2(50) NOT NULL,
        seat_price NUMBER NOT NULL
    );

CREATE TABLE train_food (
        item_id NUMBER PRIMARY KEY,
        item_name VARCHAR2(100) NOT NULL,
        price NUMBER NOT NULL
    );

CREATE TABLE train_booking (
        booking_id NUMBER PRIMARY KEY,
        booking_number VARCHAR2(20) NOT NULL,
        journey_date DATE NOT NULL,
        train_id NUMBER NOT NULL,
        passenger_id NUMBER NOT NULL,
        number_of_tickets NUMBER NOT NULL,
        ticket_amount NUMBER NOT NULL,
        food_amount NUMBER NOT NULL,
        total_amount NUMBER NOT NULL,
        payment_mode VARCHAR2(50) NOT NULL,
        FOREIGN KEY (train_id) REFERENCES train(train_id),
        FOREIGN KEY (passenger_id) REFERENCES passenger(passenger_id)
    );

CREATE TABLE train_booking_food (
        booking_id NUMBER NOT NULL,
        item_id NUMBER NOT NULL,
        quantity NUMBER NOT NULL,
        amount NUMBER NOT NULL,
        PRIMARY KEY (booking_id, item_id),
        FOREIGN KEY (booking_id) REFERENCES train_booking(booking_id),
        FOREIGN KEY (item_id) REFERENCES train_food(item_id)
    );

CREATE TABLE train_booking_seat (
        booking_id NUMBER NOT NULL,
        seat_id NUMBER NOT NULL,
        price NUMBER NOT NULL,
        PRIMARY KEY (booking_id, seat_id),
        FOREIGN KEY (booking_id) REFERENCES train_booking(booking_id),
        FOREIGN KEY (seat_id) REFERENCES train_seat(seat_id)
    );

        INSERT INTO passenger VALUES (1, 'Maheswaran', 40);
        INSERT INTO passenger VALUES (2, 'Josh', 60);
        INSERT INTO passenger VALUES (3, 'Dhaheen', 80);
        INSERT INTO passenger VALUES (4, 'Pitchumani', 55);
        INSERT INTO passenger VALUES (5, 'Bhagya', 95);
        INSERT INTO passenger VALUES (6, 'Nayana', 82);

        INSERT INTO train VALUES (1, 'Rockfort Exp', 'Chennai-Trichy');
        INSERT INTO train VALUES (2, 'Pandian Exp', 'Chennai-Madurai');
        INSERT INTO train VALUES (3, 'Mangalore Exp', 'Chennai-Mangalore');

        INSERT INTO train_seat VALUES (1, 'S1-01', 'Sleeper', 500);
        INSERT INTO train_seat VALUES (2, 'S1-02', 'Sleeper', 500);
        INSERT INTO train_seat VALUES (3, 'S1-03', 'Sleeper', 500);
        INSERT INTO train_seat VALUES (4, 'A1-01', 'AC', 1000);
        INSERT INTO train_seat VALUES (5, 'A1-02', 'AC', 1000);
        INSERT INTO train_seat VALUES (6, 'A1-03', 'AC', 1000);
        INSERT INTO train_seat VALUES (7, 'S2-01', 'Sleeper', 500);
        INSERT INTO train_seat VALUES (8, 'S2-02', 'Sleeper', 500);
        INSERT INTO train_seat VALUES (9, 'S2-03', 'Sleeper', 500);

        INSERT INTO train_food VALUES (1, 'Samosa', 60);
        INSERT INTO train_food VALUES (2, 'Coffee', 40);
        INSERT INTO train_food VALUES (3, 'Popcorn', 100);
        INSERT INTO train_food VALUES (4, 'Veg Meal', 150);
        INSERT INTO train_food VALUES (5, 'Non-Veg Meal', 200);

        INSERT INTO train_booking VALUES (1, 'B001', TO_DATE('2024-11-18', 'YYYY-MM-DD'), 1, 1, 3, 1500, 300, 1800, 'UPI');
        INSERT INTO train_booking VALUES (2, 'B002', TO_DATE('2024-11-18', 'YYYY-MM-DD'), 2, 2, 2, 2000, 300, 2300, 'Card');
        INSERT INTO train_booking VALUES (3, 'B003', TO_DATE('2024-11-18', 'YYYY-MM-DD'), 3, 3, 1, 1000, 200, 1200, 'Cash');
        INSERT INTO train_booking VALUES (4, 'B004', TO_DATE('2024-11-19', 'YYYY-MM-DD'), 1, 4, 1, 500, 100, 600, 'UPI');
        INSERT INTO train_booking VALUES (5, 'B005', TO_DATE('2024-11-19', 'YYYY-MM-DD'), 2, 5, 2, 2000, 400, 2400, 'UPI');
        INSERT INTO train_booking VALUES (6, 'B006', TO_DATE('2024-11-19', 'YYYY-MM-DD'), 3, 6, 1, 1000, 200, 1200, 'Card');

        INSERT INTO train_booking_seat VALUES (1, 1, 500);
        INSERT INTO train_booking_seat VALUES (1, 2, 500);
        INSERT INTO train_booking_seat VALUES (1, 3, 500);
        INSERT INTO train_booking_seat VALUES (2, 4, 1000);
        INSERT INTO train_booking_seat VALUES (2, 5, 1000);
        INSERT INTO train_booking_seat VALUES (3, 6, 1000);

        INSERT INTO train_booking_food VALUES (1, 1, 2, 120);
        INSERT INTO train_booking_food VALUES (1, 2, 2, 80);
        INSERT INTO train_booking_food VALUES (2, 4, 2, 300);
        INSERT INTO train_booking_food VALUES (3, 3, 2, 200);

        COMMIT;
    