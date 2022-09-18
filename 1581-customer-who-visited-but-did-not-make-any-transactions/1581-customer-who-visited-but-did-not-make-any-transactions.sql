WITH no_trans AS (
 SELECT v.customer_id, t.visit_id
    FROM Visits v
    LEFT JOIN Transactions t
    ON v.visit_id = t.visit_id
    WHERE t.transaction_id is null
)
SELECT customer_id, count(*) as count_no_trans
FROM no_trans
GROUP BY customer_id
