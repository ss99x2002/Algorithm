-- 2022년도 한해 평가 점수 가장 높은 사원 정보 조회
-- 가장 높은 사원들의 점수, 사번, 성명, 직책, 이메일 조회
-- 평가 점수 = (상 + 하반기 점수), 평가 점수 as SCORE

SELECT SUM(hg.SCORE) as SCORE, he.EMP_NO as EMP_NO, he.EMP_NAME as EMP_NAME,
he.POSITION as POSITION, he.EMAIL as EMAIL
FROM HR_EMPLOYEES as he JOIN HR_GRADE as hg
ON he.EMP_NO = hg.EMP_NO
GROUP BY he.EMP_NO, he.EMP_NAME
HAVING SCORE = (
    SELECT MAX(SCORE_SUM)
    FROM (
          SELECT SUM(hg2.SCORE) AS SCORE_SUM
    FROM HR_EMPLOYEES AS he2
    JOIN HR_GRADE AS hg2
    ON he2.EMP_NO = hg2.EMP_NO
    GROUP BY he2.EMP_NO
  ) as subT
)
ORDER BY he.EMP_NO ASC