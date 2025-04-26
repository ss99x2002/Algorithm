-- 사원별 성과금 정보 조회
-- 사번, 성명, 평가 등급, 성과금 조회
-- 평가등급 : GRADE, 성과금 : BONUS
-- 사번 기준 ASC 


SELECT he.EMP_NO as EMP_NO, he.EMP_NAME as EMP_NAME, (CASE
        WHEN AVG(hg.score) >= 96 THEN 'S'
        WHEN AVG(hg.score) >= 90 AND  AVG(hg.score) < 96 THEN 'A'
        WHEN AVG(hg.score) >= 80 AND  AVG(hg.score) < 90 THEN 'B'
        ELSE 'C'
      END) as GRADE, 
      (CASE
        WHEN AVG(hg.score) >= 96 THEN he.sal * 0.2
        WHEN AVG(hg.score) >= 90 AND  AVG(hg.score) < 96 THEN he.sal * 0.15
        WHEN AVG(hg.score) >= 80 AND  AVG(hg.score) < 90 THEN he.sal * 0.1
        ELSE 0
      END) as BONUS
FROM HR_EMPLOYEES as he JOIN HR_GRADE as hg 
ON he.EMP_NO = hg.EMP_NO
GROUP BY he.EMP_NO, he.EMP_NAME
ORDER BY he.EMP_NO ASC