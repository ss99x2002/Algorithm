-- product와 order테이블에 생산일자가 2022-05인 식품들의 id, 이름, 총매출 조회 sql
-- order by desc 총매출
-- asc 식품 id
SELECT fp.product_id, fp.product_name, SUM(fp.price * fo.amount) as total_sales
FROM FOOD_PRODUCT as fp join FOOD_ORDER as fo
ON fp.product_id = fo.product_id
WHERE produce_date BETWEEN '2022-05-01' AND '2022-05-31'
GROUP BY fp.product_id
ORDER BY total_sales DESC, fp.product_id ASC