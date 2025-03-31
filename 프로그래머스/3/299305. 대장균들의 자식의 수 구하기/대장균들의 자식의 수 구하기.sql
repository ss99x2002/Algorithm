select e1.id, coalesce(child_count, 0) as child_count 
from ECOLI_DATA as e1
left join (
    select parent_id, count(*) as child_count 
    from ECOLI_DATA
    group by parent_id
) as e2 on e1.id = e2.parent_id
order by e1.id asc
