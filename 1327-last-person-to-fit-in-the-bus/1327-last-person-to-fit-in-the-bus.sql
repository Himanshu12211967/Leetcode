SELECT person_name
FROM (
    SELECT 
        person_name,
        weight,
        turn,
        @sum := @sum + weight AS total_weight
    FROM Queue, (SELECT @sum := 0) AS init
    ORDER BY turn
) AS boarded
WHERE total_weight <= 1000
ORDER BY total_weight DESC
LIMIT 1;
