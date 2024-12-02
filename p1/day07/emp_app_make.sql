-- Install vsc extensiion: "Oracle Developer Tools for VS Code"
-- $ sqlplus system/123@localhost:1521/XEPDB1 as sysdba
-- sql> 
CREATE USER emp_db IDENTIFIED BY 123;

GRANT CONNECT, RESOURCE TO emp_db;

ALTER USER emp_db QUOTA UNLIMITED ON USERS;

-- -CONNECT emp_db/4321@localhost:1521/XEPDB1;
