using System;
using System.ComponentModel.DataAnnotations;

namespace webcalculator.Models
{
    public class Operation
    {
        [Display(Name = "First Number")]
        public double NumberA { get; set; }

        [Display(Name = "Second Number")]
        public double NumberB { get; set; }

        [Display(Name = "Result")]
        public double Result { get; set; }

        [Display(Name = "Operation")]
        public OperationType OperationType { get; set; }
    }
    public enum OperationType
    {
        Addition,
        Multiplication,
        Division,
        Subtraction,
        Percentage
    }
}
