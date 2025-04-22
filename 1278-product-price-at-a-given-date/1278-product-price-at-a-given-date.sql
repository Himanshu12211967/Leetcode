SELECT 
    p.product_id,
    COALESCE(lp.new_price, 10) AS price
FROM 
    (SELECT DISTINCT product_id FROM Products) p
LEFT JOIN (
    SELECT p1.product_id, p1.new_price
    FROM Products p1
    WHERE p1.change_date <= '2019-08-16'
    AND NOT EXISTS (
        SELECT 1 FROM Products p2
        WHERE p2.product_id = p1.product_id
          AND p2.change_date <= '2019-08-16'
          AND p2.change_date > p1.change_date
    )
) lp ON p.product_id = lp.product_id;
