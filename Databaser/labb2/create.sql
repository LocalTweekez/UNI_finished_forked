-- Create all tables
CREATE TABLE store(
store_id INT NOT NULL,
store_name VARCHAR(255),
phonenumber VARCHAR(255),
city VARCHAR(255),
zip VARCHAR(255),
street VARCHAR(255),
buildingnumber INT);

CREATE TABLE employee(
employee_id INT NOT NULL,
manager_id INT,
salary FLOAT,
fname VARCHAR(255), 
lname VARCHAR(255),
store_id INT);

CREATE TABLE movie(
movie_id INT NOT NULL,
titel VARCHAR(255),
movielength TIME,
category VARCHAR(255),
rating FLOAT);

CREATE TABLE movie_stars(
star_name VARCHAR(100),
movie_id INT);

CREATE TABLE movie_director(
director_name VARCHAR(100),
movie_id INT);

CREATE TABLE customer(
customer_id INT NOT NULL,
starting_date DATE,
address VARCHAR(255),
fname VARCHAR(255),
lname VARCHAR(255),
store_id INT NOT NULL);

CREATE TABLE STORE_HAVE_MOVIES(
quantity INT,
price FLOAT,
shelfnumber INT,
store_id INT NOT NULL,
movie_id INT NOT NULL);

CREATE TABLE customer_can_reserve(
latest_date DATE,
movie_id INT NOT NULL,
customer_id INT NOT NULL);

CREATE TABLE customer_can_rent(
rental_date DATE,
return_date DATE NOT NULL,
movie_id INT NOT NULL,
customer_id INT NOT NULL);

