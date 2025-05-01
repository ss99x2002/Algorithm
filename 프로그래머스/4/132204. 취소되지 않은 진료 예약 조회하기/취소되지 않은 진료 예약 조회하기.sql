-- 2022년 4월 13일 취소되지 않은 CS 흉부외과 진료 예약 내역 조회 SQL
-- 진료예약번호, 환자 이름, 환자 번호, 진료과코드, 의사이름, 진료예약일시 항목 출력
-- 진료예약일시 ASC

-- APNT_CNCL_YMD : 예약 취소 날짜를 의미
-- APNT_CNCL_YN : 예약 취소 여부 

-- 예약일은 4월 13일인데 취소가 안된 애들을 구해야한다? 

SELECT a.APNT_NO, p.PT_NAME, p.PT_NO, a.MCDP_CD, d.DR_NAME, a.APNT_YMD
FROM APPOINTMENT as a JOIN DOCTOR as d 
ON a.MDDR_ID = d.DR_ID
JOIN PATIENT as p
ON a.PT_NO = p.PT_NO
WHERE a.APNT_CNCL_YN = 'N' 
AND DATE(a.APNT_YMD) = '2022-04-13'
AND a.MCDP_CD = 'CS'
ORDER BY a.APNT_YMD ASC
