-- 경제 카테고리에 속하는 도서 id, 저자명, 출판일 리스트 출력
-- 출판일 기준 오름차순 정렬
SELECT b.book_id, a.author_name,  CAST(DATE(b.published_date) AS CHAR)  as published_date
FROM book as b join author as a on b.author_id = a.author_id
WHERE b.category = '경제'
ORDER BY published_date ASC;