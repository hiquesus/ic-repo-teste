-- Keep a log of any SQL queries you execute as you solve the mystery.

-- see what happened at the crime scene

SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street = 'Humphrey Street';

-- check the bakery

SELECT transcript FROM interviews WHERE day = 28 AND month = 7 AND year = 2021 AND transcript LIKE '%bakery%';

-- find out who was at the atm earlier

SELECT atm_transactions.transaction_type, people.name FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE atm_transactions.day = 28
AND atm_transactions.month = 7
AND atm_transactions.year = 2021
AND atm_transactions.transaction_type = 'withdraw'
AND atm_location = 'Leggett Street';

--+------------------+---------+
--| transaction_type |  name   |
--+------------------+---------+
--| withdraw         | Bruce   |
--| withdraw         | Diana   |
--| withdraw         | Brooke  |
--| withdraw         | Kenny   |
--| withdraw         | Iman    |
--| withdraw         | Luca    |
--| withdraw         | Taylor  |
--| withdraw         | Benista |
--+------------------+---------+

-- car logs

SELECT bakery_security_logs.activity, bakery_security_logs.license_plate, people.name FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE bakery_security_logs.day = 28
AND bakery_security_logs.month = 7
AND bakery_security_logs.year = 2021
AND bakery_security_logs.hour = 10
AND bakery_security_logs.minute >= 15 AND bakery_security_logs.minute <=25;

--notes
--+----------+---------------+---------+
--| activity | license_plate |  name   |
--+----------+---------------+---------+
--| exit     | 5P2BI95       | Vanessa |
--| exit     | 94KL13X       | Bruce   |
--| exit     | 6P58WS2       | Barry   |
--| exit     | 4328GD8       | Luca    |
--| exit     | G412CB7       | Sofia   |
--| exit     | L93JTIZ       | Iman    |
--| exit     | 322W7JE       | Diana   |
--| exit     | 0NTHK55       | Kelsey  |
--+----------+---------------+---------+

--SUSPECTS: (for now)

--Bruce
--Luca
--Diana
--Iman

-- see who of those called someone

SELECT phone_calls.caller, people.name, phone_calls.duration FROM phone_calls
JOIN people ON people.phone_number = phone_calls.caller
WHERE year = 2021
AND day = 28
AND month = 7
AND duration < 60;

-- and those who received the call

SELECT phone_calls.receiver, people.name, phone_calls.duration FROM phone_calls
JOIN people ON people.phone_number = phone_calls.receiver
WHERE year = 2021
AND day = 28
AND month = 7
AND duration < 60;

--SUSPECTS:

--Bruce (45s call) - (367) 555-5533
--Diana (49s call) - (770) 555-1861

-- duos: (respectively)

--Robin (45s call) - (375) 555-8161
--Philip (49s call) - (725) 555-3243

-- check flights leaving

SELECT flights.hour, flights.minute, airports.full_name, airports.city, flights.id FROM flights
JOIN airports ON airports.id = flights.origin_airport_id
WHERE flights.year = 2021
AND flights.day = 29
AND flights.month = 7
ORDER BY flights.hour ASC;

--check flights ariving

SELECT flights.hour, flights.minute, airports.full_name, airports.city, flights.id FROM flights
JOIN airports ON airports.id = flights.destination_airport_id
WHERE flights.year = 2021
AND flights.day = 29
AND flights.month = 7
ORDER BY flights.hour ASC;

-- EARLIEST FLIGHT:
-- FROM Fiftyville at 8:20 TO New York City; ID = 36

-- check flight passengers

SELECT people.name FROM people
JOIN passengers ON passengers.passport_number = people.passport_number
JOIN flights ON passengers.flight_id = flights.id
WHERE flights.id = 36;

-- THIEF:

-- Bruce
-- (together with Robin)