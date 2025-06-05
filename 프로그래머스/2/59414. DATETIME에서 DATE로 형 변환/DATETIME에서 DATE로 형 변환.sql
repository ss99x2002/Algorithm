-- ANIMALS_INS 테이블에 대해 
-- 아이디, 이름, 들어온 날짜 조회하는 SQL문 작성
-- 아이디 순 ASC 
SELECT ANIMAL_ID, NAME, DATE_FORMAT(DATETIME, '%Y-%m-%d') as '날짜'
FROM ANIMAL_INS
ORDER BY ANIMAL_ID ASC