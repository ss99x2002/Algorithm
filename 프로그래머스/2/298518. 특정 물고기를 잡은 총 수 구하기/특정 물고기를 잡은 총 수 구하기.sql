select count(*) as FISH_COUNT
from FISH_INFO
where FISH_TYPE IN (
    SELECT 
        FISH_TYPE
    FROM
        FISH_NAME_INFO
    WHERE FISH_NAME IN ('BASS', 'SNAPPER')
)