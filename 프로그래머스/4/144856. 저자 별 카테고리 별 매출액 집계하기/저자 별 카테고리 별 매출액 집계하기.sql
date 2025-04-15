-- 코드를 입력하세요
-- 2022 1월 기준 저자별, 카테고리별 매출액 (판매량 * 판매가) 구하고
-- 저자 id, 저자명, 카테고리, 매출액 리스트 구하는 sql
-- 저자 id 오름차순, 카테고리 내림차순
SELECT a.author_id, a.author_name, b.category, sum(b.price * bs.sales) as total_sales
FROM BOOK AS b
JOIN AUTHOR AS a ON b.author_id = a.author_id
JOIN BOOK_SALES AS bs ON b.book_id = bs.book_id
WHERE bs.sales_date between '2022-01-01' and '2022-01-31'
GROUP BY a.author_id, b.category
ORDER BY a.author_id asc, b.category desc