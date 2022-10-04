using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Logging;
using webcalculator.Models;

namespace webcalculator.Controllers
{
    public class HomeController : Controller
    {
        private readonly ILogger<HomeController> _logger;

        public HomeController(ILogger<HomeController> logger)
        {
            _logger = logger;
        }

        public IActionResult Index()
        {
            return View();
        }

        [HttpPost]
        public IActionResult Index(Operation model)
        {
            if (model.OperationType == OperationType.Addition)
            {
                model.Result = model.NumberA + model.NumberB;
            }
            else if (model.OperationType == OperationType.Multiplication)
            {
                model.Result = model.NumberA * model.NumberB;
            }
            else if (model.OperationType == OperationType.Subtraction)
            {
                model.Result = model.NumberA - model.NumberB;
            }
            else if (model.OperationType == OperationType.Division)
            {
                model.Result = model.NumberA / model.NumberB;
            }
            return View(model);
        }


        [HttpPost]
        public double Calculation(Operation model)
        {
            if (model.OperationType == OperationType.Addition)
            {
                model.Result = model.NumberA + model.NumberB;
            }
            else if (model.OperationType == OperationType.Multiplication)
            {
                model.Result = model.NumberA * model.NumberB;
            }
            else if (model.OperationType == OperationType.Subtraction)
            {
                model.Result = model.NumberA - model.NumberB;
            }
            else if (model.OperationType == OperationType.Division)
            {
                model.Result = model.NumberA / model.NumberB;
            }else if(model.OperationType == OperationType.Percentage)
            {
                model.Result = Convert.ToDouble((model.NumberA/100));
            }
            return model.Result;
        }


        public IActionResult Privacy()
        {
            return View();
        }

        [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
        public IActionResult Error()
        {
            return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
        }
    }
}
