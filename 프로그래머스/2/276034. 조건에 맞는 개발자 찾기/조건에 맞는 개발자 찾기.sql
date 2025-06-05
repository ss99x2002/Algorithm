-- C# 이나 Python 스킬 가진 개발자 정보 조회
-- 개발자 id, 이메일, 이름, 성 조회 SQL
-- id 기준 ASC
-- ⭐️ WITH 연달아 2개 사용할 수 없음.
-- 어떤 스킬코드를 갖고있다고 하면, &했을때 1이상으로 존재하므로, >0으로 비교하는 것 잊지말기. 

WITH C_SHOP AS (
    SELECT CODE as SKILL_CODE
    FROM SKILLCODES
    WHERE NAME = 'C#'
), PYTHON AS (
    SELECT CODE as SKILL_CODE
    FROM SKILLCODES
    WHERE NAME = 'Python'
)

SELECT d.ID, d.EMAIL, d.FIRST_NAME, d.LAST_NAME
FROM DEVELOPERS as d, C_SHOP as c, PYTHON as p 
WHERE d.SKILL_CODE & c.SKILL_CODE  > 0 OR d.SKILL_CODE & p.SKILL_CODE > 0
ORDER BY d.ID ASC

