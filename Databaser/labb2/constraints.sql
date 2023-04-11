
ALTER TABLE store ADD CONSTRAINT store_pk PRIMARY KEY(store_id);
ALTER TABLE store MODIFY COLUMN store_id INT auto_increment;

ALTER TABLE employee ADD CONSTRAINT employee_pk PRIMARY KEY(employee_id);
ALTER TABLE employee MODIFY COLUMN employee_id INT auto_increment;
ALTER TABLE employee auto_increment = 100;

ALTER TABLE customer ADD CONSTRAINT customer_pk PRIMARY KEY(customer_id);
ALTER TABLE customer MODIFY COLUMN customer_id INT auto_increment ;
ALTER TABLE customer auto_increment = 1700;

ALTER TABLE movie ADD CONSTRAINT movie_pk PRIMARY KEY(movie_id);
ALTER TABLE movie MODIFY COLUMN movie_id INT auto_increment;
ALTER TABLE movie auto_increment = 10000;

ALTER TABLE movie_stars ADD CONSTRAINT movie_stars_pk PRIMARY KEY (movie_id, star_name);
ALTER TABLE movie_stars ADD CONSTRAINT star_fk FOREIGN KEY (movie_id) REFERENCES movie(movie_id);

ALTER TABLE movie_director ADD CONSTRAINT movie_director PRIMARY KEY (movie_id, director_name);
ALTER TABLE movie_director ADD CONSTRAINT director_fk FOREIGN KEY (movie_id) REFERENCES movie(movie_id);


ALTER TABLE STORE_HAVE_MOVIES ADD CONSTRAINT store_movie_pk PRIMARY KEY (store_id, movie_id);
ALTER TABLE customer_can_rent ADD CONSTRAINT customer_movie_pk PRIMARY KEY (customer_id, movie_id);
ALTER TABLE customer_can_reserve ADD CONSTRAINT customer_movie_pk PRIMARY KEY (customer_id, movie_id); 


-- employee and manager 
ALTER TABLE employee ADD CONSTRAINT e_store_fk FOREIGN KEY (store_id) REFERENCES store(store_id) ON UPDATE CASCADE;
ALTER TABLE employee ADD CONSTRAINT manager_fk FOREIGN KEY (manager_id) REFERENCES employee(employee_id) ON UPDATE CASCADE;
-- store have movies
ALTER TABLE STORE_HAVE_MOVIES ADD CONSTRAINT store_has_fk FOREIGN KEY (store_id) REFERENCES store(store_id) ON UPDATE CASCADE;
ALTER TABLE STORE_HAVE_MOVIES ADD CONSTRAINT has_movie_fk FOREIGN KEY (movie_id) REFERENCES movie(movie_id) ON UPDATE CASCADE;
-- customer relation
ALTER TABLE customer ADD CONSTRAINT c_store_fk FOREIGN KEY (store_id) REFERENCES store(store_id) ON UPDATE CASCADE;

-- movie and customer
ALTER TABLE customer_can_rent ADD CONSTRAINT rent_customer_fk FOREIGN KEY (customer_id) REFERENCES customer(customer_id) ON UPDATE CASCADE;
ALTER TABLE customer_can_rent ADD CONSTRAINT rent_movie_fk FOREIGN KEY (movie_id) REFERENCES movie(movie_id) ON UPDATE CASCADE;

ALTER TABLE customer_can_reserve ADD CONSTRAINT reserve_customer_fk FOREIGN KEY (customer_id) REFERENCES customer(customer_id) ON UPDATE CASCADE;
ALTER TABLE customer_can_reserve  ADD CONSTRAINT reserve_movie_fk FOREIGN KEY (movie_id) REFERENCES movie(movie_id) ON UPDATE CASCADE;
