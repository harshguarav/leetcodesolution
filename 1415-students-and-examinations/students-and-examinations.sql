select 
    st.student_id,
    st.student_name,
    sb.subject_name,
    count(ex.subject_name) as attended_exams
from
    students st
join
    subjects sb
left join
    examinations ex
    on ex.student_id=st.student_id
    and ex.subject_name=sb.subject_name
group by 
    -- st.student_id
    st.student_name,
    st.student_id,
    sb.subject_name

order by
st.student_id,
sb.subject_name;
    
