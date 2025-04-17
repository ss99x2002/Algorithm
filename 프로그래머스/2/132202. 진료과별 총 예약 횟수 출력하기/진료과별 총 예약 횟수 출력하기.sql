-- appointment 에서
-- 2022-05에 예약한 환자수를 
-- 진료과코드 별로 조회 sql
-- 이 때 컬럼명 - 진료과코드, 5월 예약건수 로 지정
-- 예약확자수 기준 오름차순, 진료코드순 오름차순
SELECT MCDP_CD as '진료과코드', count(*) as '5월예약건수'
FROM APPOINTMENT
WHERE APNT_YMD between '2022-05-01' AND '2022-05-31'
GROUP BY MCDP_CD
ORDER BY 5월예약건수 asc, 진료과코드 asc