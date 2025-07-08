-- 경제에 속하는 도서들의 id, 저자병, 출판일 출력
-- 출판일 오름차순 

SELECT b.book_id as book_id, a.author_name as AUTHOR_NAME,
DATE_FORMAT(b.published_date, '%Y-%m-%d') as PUBLISHED_DATE
FROM BOOK as b JOIN  AUTHOR as a
ON b.author_id = a.author_id
WHERE b.category = '경제'
ORDER BY b.published_date asc 
