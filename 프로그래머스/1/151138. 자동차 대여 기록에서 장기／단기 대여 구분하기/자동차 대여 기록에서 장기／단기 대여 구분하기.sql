-- 대여 시작일이 2022년 9월에 속하는 대여 기록에 대해
-- 대여기간이 30일 이상이면 '장기 대여', 아니면 '단기 대여'로 표시하는 as RENT_TYPE
-- 대여기록 ID DESC
SELECT HISTORY_ID, CAR_ID, DATE_FORMAT(START_DATE, "%Y-%m-%d") as START_DATE, 
DATE_FORMAT(END_DATE, "%Y-%m-%d") as END_DATE, 
CASE
    WHEN DATEDIFF(END_DATE, START_DATE)+1 >=30  THEN '장기 대여'
    ELSE '단기 대여'
END as RENTAL_TYPE
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
WHERE START_DATE >= '2022-09-01' AND START_DATE <= '2022-09-30'
ORDER BY HISTORY_ID DESC

-- CASE END 문 사이 WHEN 넣을 때 괄호는 없는게 옳은 문법이다.
-- DATEDIFF(end시간, start시간)