
INSERT INTO store VALUES
(DEFAULT, 'movienight','708-805-0001','Wheeling','60090', 'Lewis Street',4568),
(DEFAULT, 'WatchAlong','408-253-2886','San Jose','95129', ' Hide A Way Road',1376),
(DEFAULT, 'Cmovie','678-857-8179','Marietta','30067', 'Edinton Drive',1235),
(DEFAULT, 'whatNsee','617-588-4055','Cambridge','02141', 'Cedar Lane',1945);

INSERT INTO movie(titel, movielength, category, rating) VALUES
('Bullet Train', '2:07:00','Action, Comedy, Thriller' , 7.4),
('Thor love and thunder', '1:58:00','Action, Comedy, Adventure' , 6.4),
('Jurassic World Dominion', '2:27:00','Action, sci-fi, Thriller' , 5.7),
('Day Shift', '1:53:00','Action, Comedy, Fantasy' , 6.1),
('Death at a funeral', '1:32:00','Comedy, Drama' , 5.7),
('Girls Trip', '2:02:00','Adventure, Comedy, Drama' , 6.2),
('Ride along', '1:39:00','Action, Comedy, crime' , 6.1),
('After ever happy', '1:59:00','Drama, Romance' , 4.4),
('Norbit', '1:43:00','Action, romance' , 4.1),
('Lilo & stitch', '1:25:00','Animation, Comedy, Adventure' , 7.3),
('Teenage Mutant Ninja turtles', '1:41:00','Action, Comedy, Adventure' , 10.0),
('Kung Fu panda', '1:32:00','Action, Animation, Adventure' , 10.0);




INSERT INTO movie_stars VALUES
('David Leicht', 10000),
('Brad Pitt', 10000),
('Joey King', 10000),
('Taika Waititi' , 10001),
('Chris Hemsworth', 10001),
('Nathalie Portman', 10001),
('Chris pratt', 10002),
('Bryce Dallas Howard', 10002),
('Jamie Foxx', 10003),
('Dave Franco ', 10003),
('David Leicht', 10004),
('Brad Pitt', 10004),
('Joey King', 10004),
('Taika Waititi', 10005),
('Chris Hemsworth', 10005),
('Nathalie Portman', 10005),
('Chris pratt', 10006),
('Bryce Dallas Howard', 10006),
('Jamie Foxx', 10007),
('Dave Franco ' , 10007),
('David Leicht' , 10008),
('Brad Pitt', 10008),
('Joey King',10008),
('Taika Waititi',10009),
('Chris Hemsworth', 10009),
('Nathalie Portman', 10009),
('Chris pratt', 10010),
('Bryce Dallas Howard', 10010),
('Jamie Foxx', 10011),
('Dave Franco ', 10011);

INSERT INTO movie_director VALUES
('David Leicht', 10000),
('Taika Waititi', 10001),
('Colin Trevorrow', 10002),
('J.J. Perry ' , 10003),
('David Leicht' , 10004),
('Taika Waititi', 10005),
('Colin Trevorrow' , 10006),
('J.J. Perry ', 10007),
('David Leicht', 10008),
('Taika Waititi' , 10009),
('Colin Trevorrow' , 10010),
('J.J. Perry ', 10011);



INSERT INTO employee(fname, lname, salary, manager_id, store_id) values
('Hanna','Gigi',21500.24, NULL, 1),
('Bobby', 'Svensson', 45032.5, 100, 1),
('Björn', 'Fredriksson', 20000.00, 100, 2),
('Emma','Ikea',8000.37, 100, 2),
('Kuresh','Bilal',14000.00, NULL, 3),
('Angelina','Gunnarsdotter',16070.46, 104, 3),
('Sevala','Ahmad',3000.00, 104, 4),
('Nikolas','Fridolf',17000.00, 104, 4);

INSERT INTO customer Values
(Default, '2017-02-07', 'Nyängsvägen 15 sundsvall', 'Lisbet', 'Magnusson', 1 ),
(Default, '2019-02-17', 'Träteljagatan strömsta', 'christian', 'henriksson',1 ),
(Default, '2015-05-12', 'Nyängsvägen 15 sundsvall', 'Lisbet', 'Magnusson',2 ),
(Default, '2017-10-07', 'fagermovägen ödershög', 'William', 'Ekström', 2),
(Default, '2022-8-11', 'pelargatan kopperberg', 'Mikaela', 'stenlund', 3),
(Default, '2021-11-09', 'baranstigen avesta', 'hannes', 'åström', 3),
(Default, '2019-02-07', 'oskarsgatan 14 sjöstad', 'johanna', 'möller',4 ),
(Default, '2017-10-26', 'emausgatan silvestad', 'abdulla', 'abdison', 4),
(Default, '2017-02-07', 'silkgatan 45 halmstad', 'hejma', 'martinsson',4 ),
(Default, '2018-11-07', 'hejargatan ovestad', 'martin', 'olofström',4);

INSERT INTO STORE_HAVE_MOVIES VALUES
(5, 7.99, 13, 1,10000), 
(10, 11.99, 13, 1,10001),
(4, 21.99, 13, 1,10002),
(6, 42.99, 33, 1,10003),
(7, 131.99, 43, 1,10004),
(9, 16.99, 35, 1,10005),
(9, 28.99, 13, 1,10006),
(5, 39.99, 53, 1,10007),
(5, 59.99, 3, 1,10008),
(7, 89.99, 63, 1,10009),
(7, 19.99, 33, 1,10010),
(8, 9.99, 23, 1,10011);
INSERT INTO STORE_HAVE_MOVIES VALUES
(5, 7.99, 0, 2,10000), 
(10, 11.99, 0, 2,10001),
(4, 11.99, 0, 2,10002),
(6, 52.99, 0, 2,10003),
(7, 231.99, 0, 2,10004),
(9, 16.99, 1, 2,10005),
(9, 58.99, 2, 2,10006),
(5, 19.99, 2, 2,10007),
(5, 59.99, 2, 2,10008),
(7, 80.99, 3, 2,10009),
(7, 9.99, 3, 2,10010),
(8, 19.99, 3, 2,10011);
INSERT INTO STORE_HAVE_MOVIES VALUES
(5, 17.99, 13, 3,10000), 
(10,11.99, 13, 3,10001),
(4, 61.99, 11, 3,10002),
(6, 32.99, 13, 3,10003),
(7, 131.99, 13,3,10004),
(9, 26.99, 31, 3,10005),
(9, 28.99, 32, 3,10006),
(5, 59.99, 43, 3,10007),
(5, 89.99, 33, 3,10008),
(7, 78.99, 23, 3,10009),
(7, 19.99, 21, 3,10010),
(8, 9.99, 11, 3,10011);
INSERT INTO STORE_HAVE_MOVIES VALUES
(5, 7.99, 21, 4,10000), 
(10, 11.99, 21,4,10001),
(4, 21.99, 16, 4,10002),
(6, 42.99, 16, 4,10003),
(7, 139.99, 16, 4,10004),
(9, 19.99, 13, 4,10005),
(9, 22.99, 16, 4,10006),
(5, 31.99, 13, 4,10007),
(5, 54.99, 23, 4,10008),
(7, 86.99, 53, 4,10009),
(7, 11.99, 33, 4,10010),
(8, 9.99, 43, 4,10011);


INSERT INTO customer_can_reserve VALUES
(STR_TO_DATE('11-NOV-2022','%d-%M-%Y'),10008,1706),
(STR_TO_DATE('04-DEC-2022','%d-%M-%Y'),10011,1701),
(STR_TO_DATE('04-DEC-2022','%d-%M-%Y'),10001,1701);
#STR_TO_DATE('23-JAN-1982','%d-%M-%Y')
INSERT INTO customer_can_rent VALUES
('2022-09-24','2022-12-24',10004,1707),
('2022-08-01','2022-11-21',10009,1702),
('2022-09-01','2022-12-06',10008,1703),
('2022-12-01','2022-11-11',10009,1704),
('2022-12-01','2022-11-11',10001,1709);

