CREATE USER railway_db IDENTIFIED BY 123;
GRANT CONNECT, RESOURCE TO railway_db;
ALTER USER railway_db QUOTA UNLIMITED ON USERS; 