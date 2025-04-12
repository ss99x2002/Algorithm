-- 상품코드별 매출액 (판매가 * 판매량) 합계 출력하는 sql
-- 매출액 기준 desc, 상품코드 기준 asc
SELECT p.product_code, SUM(p.price * os.sales_amount) as sales
FROM product as p join offline_sale as os
on p.product_id = os.product_id
GROUP BY p.product_id
ORDER BY sales desc, p.product_code