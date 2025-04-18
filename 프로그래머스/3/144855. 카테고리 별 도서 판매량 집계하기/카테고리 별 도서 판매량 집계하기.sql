-- 2022 1월 카테고리별 도서 판매량 합산
-- 카테고리 as category, 총판매량 total_sales
-- 카테고리명 기준 asc 정렬
SELECT b.category as category, sum(bs.sales) as total_sales
FROM book as b join book_sales as bs
on b.book_id = bs.book_id
WHERE bs.sales_date between '2022-01-01' and '2022-01-31'
GROUP BY b.category
ORDER BY b.category asc