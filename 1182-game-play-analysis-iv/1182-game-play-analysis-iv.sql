WITH First_Login AS (
    SELECT player_id, MIN(event_date) AS first_login_date
    FROM Activity
    GROUP BY player_id
),
Consecutive_Logins AS (
    SELECT a.player_id
    FROM Activity a
    JOIN First_Login f ON a.player_id = f.player_id
    WHERE a.event_date = DATE_ADD(f.first_login_date, INTERVAL 1 DAY)
)
SELECT 
    ROUND(COUNT(DISTINCT c.player_id) / (SELECT COUNT(DISTINCT player_id) FROM Activity), 2) AS fraction
FROM Consecutive_Logins c;
