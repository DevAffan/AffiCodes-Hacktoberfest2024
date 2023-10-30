
import { Link, useSearchParams } from 'react-router-dom';

const Navbar = () => {
    const [searchParams] = useSearchParams();
    let todos̥Data = searchParams.get("todos");
    
  return (
   <nav>
    <Link to="/" className={todos̥Data === null ? "active" : ""} > All </Link>
    <Link to="/?todos=active" className={todos̥Data === "active" ? "active" : ""} > Active </Link>
    <Link to="/?todos=completed" className={todos̥Data === "completed" ? "active" :""} > Completed </Link>
   </nav>
  )
}

export default Navbar