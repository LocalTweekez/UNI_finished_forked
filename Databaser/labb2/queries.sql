-- lista ut alla anställda som inte har manager id 100;
	SELECT * FROM employee WHERE manager_id != 100; 
-- lista ut alla filmer som börjar på bokstaven t?
	SELECT * FROM movie WHERE titel LIKE 't%';
-- lista ut alla filmer som ska returneras mellan datumet 2022-11-21 och 2023-01-01
	SELECT * FROM customer_can_rent
    WHERE return_date BETWEEN '2022-11-21' AND '2023-01-01';
-- lista ut medelönen i varje butik och gruppera de. sortera med störst först
	SELECT 	AVG(salary), store_id
	FROM employee GROUP BY store_id
	ORDER BY AVG(salary) DESC;
-- lista ut hur många ansätllda som har mer än 15000 i lön
	
SELECT fname, SUM(salary)
FROM employee EMP,store st WHERE st.store_id=EMP.store_id
GROUP BY fname HAVING SUM(salary) > 15000;
-- Chefen 100 vill ge sina anställda 20000 i lön se till att alla hans anställda får det
	UPDATE employee SET salary = 20000 WHERE manager_id = 100;
    select * from employee;
    
    
	SELECT * FROM movie_stars, movie_director WHERE movie_director.movie_id = movie_stars.movie_id AND movie_director.director_name = movie_stars.star_name;
   