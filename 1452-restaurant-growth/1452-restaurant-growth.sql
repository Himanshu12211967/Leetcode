WITH DailyTotal AS (
    SELECT visited_on, SUM(amount) AS amount
    FROM Customer
    GROUP BY visited_on
),
Rolling7Days AS (
    SELECT 
        a.visited_on,
        SUM(b.amount) AS amount,
        ROUND(SUM(b.amount) / 7, 2) AS average_amount
    FROM DailyTotal a
    JOIN DailyTotal b
      ON b.visited_on BETWEEN DATE_SUB(a.visited_on, INTERVAL 6 DAY) AND a.visited_on
    GROUP BY a.visited_on
    HAVING COUNT(*) = 7
)
SELECT * FROM Rolling7Days
ORDER BY visited_on;
